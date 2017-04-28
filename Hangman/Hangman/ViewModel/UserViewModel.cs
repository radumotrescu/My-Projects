using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Hangman.Model;
using System.IO;
using System.Collections.ObjectModel;

namespace Hangman.ViewModel
{
	class UserViewModel
	{
		public ObservableCollection<UserModel> Users
		{
			get;
			set;
		}

		public void LoadUsers()
		{
			var users = new ObservableCollection<UserModel>();
			StreamReader sr = new StreamReader("users.txt");
			string text = sr.ReadToEnd();
			sr.Close();

			string[] names = text.Split(new char[] { ' ', '\n' });
			foreach (string name in names)
			{
				users.Add(new UserModel { Name = name, ImagePath = @"C:\image1.bmp" });
			}

			//users.Add(new UserModel { Name = "Radu", ImagePath = "abc" });

			Users = users;
		}

		public string getSelectedUserPath(string name)
		{
			foreach(UserModel user in Users)
			{
				if (user.Name == name)
					return user.ImagePath;
			}
			return null;
		}

	}
}
