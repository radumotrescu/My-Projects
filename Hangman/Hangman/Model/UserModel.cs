using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace Hangman.Model
{
	class UserModel
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

				}

			}
		}
	}
}
