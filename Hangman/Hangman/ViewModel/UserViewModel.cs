using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Hangman.Model;
using System.IO;
using System.Collections.ObjectModel;
using System.Windows.Input;


namespace Hangman.ViewModel
{
	class UserViewModel : BaseViewModel
	{
		public ObservableCollection<UserModel> Users
		{
			get;
			set;
		}

		public UserViewModel()
		{
			var users = new ObservableCollection<UserModel>();
			StreamReader sr = new StreamReader("users.txt");
			string text = sr.ReadToEnd();
			sr.Close();

			string[] names = text.Split(new char[] { ' ', '\n', '\r' });
			List<string> words = new List<string>();

			foreach (string name in names)
			{
				if (name.Length != 0)
					words.Add(name);
			}


			for (int i = 0; i < words.Count; i += 2)
			{
				string nameAux = words[i];
				string imagePathAux = words[i + 1];
				users.Add(new UserModel { Name = nameAux, ImagePath = imagePathAux });
			}


			Users = users;



			StartGameCommand = new Commands.RelayCommand(createNewGameWindow, param => CanExecuteCommand);

			NextImageCommand = new Commands.RelayCommand(changeToNextPicture, param => CanExecuteCommand);

			PreviousImageCommand = new Commands.RelayCommand(changeToPreviousPicture);

			ImageChangeCommand = new Commands.RelayCommand(changeImage);

			NewUserCommand = new Commands.RelayCommand(saveNewUser);


		}



		private void createNewGameWindow(object obj)
		{

			Windows.GameWindow gw = new Windows.GameWindow();

			gw.Content = new View.GameControl { DataContext = new ViewModel.GameViewModel(CurrentUser) };
			gw.Show();
		}

		private void changeImage(object obj)
		{
			var aux = (Model.UserModel)obj;
			string name = aux.Name;
			CurrentUser = aux.Name;
			foreach (UserModel user in Users)
			{
				if (user.Name == name)
				{
					ImagePath = user.ImagePath;
				}
			}
		}

		public string ReplaceAt(string str, int index, int length, string replace)
		{
			return str.Remove(index, Math.Min(length, str.Length - index))
					.Insert(index, replace);
		}

		private void changeToPreviousPicture(object obj)
		{
			int imageIndex = 0;
			foreach (char c in imagePath)
			{
				if (c >= '0' && c <= '9')
				{
					imageIndex = Int32.Parse(c + "");
				}
			}

			if (imageIndex > 0)
			{
				int aux = imageIndex - 1;
				ImagePath = ReplaceAt(imagePath, 24, 1, aux.ToString());
			}
		}

		private void changeToNextPicture(object obj)
		{

			int imageIndex = 0;
			foreach (char c in imagePath)
			{
				if (c >= '0' && c <= '9')
				{
					imageIndex = Int32.Parse(c + "");
				}
			}

			if (imageIndex < 8)
			{
				int aux = imageIndex + 1;
				ImagePath = ReplaceAt(imagePath, 24, 1, aux.ToString());
			}


		}

		private string imagePath = "C:\\\\ProfileImages\\\\image0.jpg";
		public string ImagePath
		{
			get
			{

				return imagePath;
			}
			set
			{
				imagePath = value;
				OnPropertyChanged("ImagePath");
			}
		}



		public string CurrentUser
		{
			get;
			set;
		}

		public string NewUserName
		{
			get;
			set;
		}



		public string getSelectedUserPath(string name)
		{
			foreach (UserModel user in Users)
			{
				if (user.Name == name)
					return user.ImagePath;
			}
			return null;
		}




		private bool canExecuteCommand = true;
		public bool CanExecuteCommand
		{
			get
			{
				return canExecuteCommand;
			}

			set
			{
				if (canExecuteCommand == value)
				{
					return;
				}
				canExecuteCommand = value;
			}
		}


		private ICommand imageChangeCommand;

		public ICommand ImageChangeCommand
		{
			get
			{
				return imageChangeCommand;
			}
			set
			{
				imageChangeCommand = value;
			}
		}



		private ICommand nextImageCommand;

		public ICommand NextImageCommand
		{
			get
			{
				return nextImageCommand;

			}
			set
			{
				nextImageCommand = value;
			}
		}

		private ICommand previousImageCommand;

		public ICommand PreviousImageCommand
		{
			get
			{
				return previousImageCommand;

			}
			set
			{
				previousImageCommand = value;
			}
		}


		private ICommand startGameCommand;
		public ICommand StartGameCommand
		{
			get
			{
				return startGameCommand;
			}
			set
			{
				startGameCommand = value;
			}
		}

		private ICommand newUserCommand;

		public ICommand NewUserCommand
		{
			get
			{
				return newUserCommand;
			}

			set
			{
				newUserCommand = value;
			}
		}

		private void saveNewUser(object obj)
		{
			StreamReader sr = new StreamReader("users.txt");
			var text = sr.ReadToEnd();
			text += '\n';
			text += NewUserName + " " + ImagePath;
			sr.Close();
			System.IO.File.WriteAllText("users.txt", string.Empty);
			StreamWriter sw = new StreamWriter("users.txt");
			sw.Write(text);
			sw.Close();
			
		}

		private ICommand DeleteUserCommand;
		

	}
}
