using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace Hangman.Model
{
	class UserModel : INotifyPropertyChanged
	{
		private string name;
		private string imagePath;


		public string Name
		{
			get
			{ return name; }

			set
			{
				if (name != value)	
				{
					name = value;
					RaisePropertyChanged("Name");
				}
			}
		}

		public string ImagePath
		{
			get { return imagePath; }
			set
			{
				if (imagePath != value)
				{
					imagePath = value;
					RaisePropertyChanged("ImagePath");
				}
					
			}
		}



		public event PropertyChangedEventHandler PropertyChanged;
		private void RaisePropertyChanged(string property)
		{
			if (PropertyChanged != null)
			{
				PropertyChanged(this, new PropertyChangedEventArgs(property));
			}
		}
	}
}
