using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Hangman.ViewModel
{
	
	class GameViewModel : BaseViewModel
	{
		
		Model.GameModel game ;

		public GameViewModel()
		{
			Game = new Model.GameModel("animals");
			imageSource = @"C:\HangmanImages\image0.jpg";

			Command = new Commands.RelayCommand(checkWord);

			NewGame = new Commands.RelayCommand(newGameMethod);

			VideoGames = new Commands.RelayCommand(videoGameCategory);
			Animals = new Commands.RelayCommand(animalsCategory);
			Sports = new Commands.RelayCommand(sportsCategory);
			AllCategories = new Commands.RelayCommand(allCategoriesCategory);
		}
		public GameViewModel(string name)
		{
			UserName = name;
			Game = new Model.GameModel("animals");
			imageSource = @"C:\HangmanImages\image0.jpg";

			Command = new Commands.RelayCommand(checkWord);

			NewGame = new Commands.RelayCommand(newGameMethod);

			VideoGames = new Commands.RelayCommand(videoGameCategory);
			Animals = new Commands.RelayCommand(animalsCategory);
			Sports = new Commands.RelayCommand(sportsCategory);
			AllCategories = new Commands.RelayCommand(allCategoriesCategory);
		}

		public Model.GameModel Game
		{
			get
			{
				return game;
			}
			set
			{
				game = value;
				OnPropertyChanged("UndiscoveredWord");
				OnPropertyChanged("ToDiscoverWord");
				OnPropertyChanged("Category");
				OnPropertyChanged("Level");
				OnPropertyChanged("Mistakes");
			}

		}

		private void allCategoriesCategory(object obj)
		{
			Game = new Model.GameModel("all");
			ImageSource = @"C:\HangmanImages\image0.jpg";
		}


		private ICommand allCategories;

		public ICommand AllCategories
		{
			get { return allCategories; }
			set { allCategories = value; }
		}

		private void sportsCategory(object obj)
		{
			Game = new Model.GameModel("sports");
			ImageSource = @"C:\HangmanImages\image0.jpg";
		}

		private ICommand sports;

		public ICommand Sports{ get { return sports; } set { sports = value; } }

		private void animalsCategory(object obj)
		{
			Game = new Model.GameModel("animals");
			ImageSource = @"C:\HangmanImages\image0.jpg";
		}

		private ICommand animals;

		public ICommand Animals { get { return animals; } set { animals = value; } }


		private void videoGameCategory(object obj)
		{
			Game = new Model.GameModel("videogames");
			ImageSource = @"C:\HangmanImages\image0.jpg";
		}

		private ICommand videoGames;

		public ICommand VideoGames { get { return videoGames; } set { videoGames = value; } }

		private void newGameMethod(object obj)
		{
			Game.setNextWord();
			Game = Game;
			ImageSource = @"C:\HangmanImages\image0.jpg";
		}

		private ICommand newGame;

		public ICommand NewGame { get { return newGame; } set { newGame = value; } }



		public string ReplaceAt(string str, int index, int length, string replace)
		{
			return str.Remove(index, Math.Min(length, str.Length - index))
					.Insert(index, replace);
		}


		private void checkWord(object obj)
		{
			var button = (System.Windows.Controls.Button)obj;
			string character =(string)button.Content;
			int index = ToDiscoverWord.IndexOf(character);
			if (index != -1)
			{
				while (index != -1)
				{
					
					string aux = ToDiscoverWord;
					ToDiscoverWord = ReplaceAt(ToDiscoverWord, index, 1, ".");
					UndiscoveredWord = ReplaceAt(UndiscoveredWord, index, 1, character);
					index = ToDiscoverWord.IndexOf(character);
				}


				checkWordFinish();
			}
			else
			{
				Mistakes++;
				nextPicture();
				checkWordFail();
			}
			//button.IsEnabled=false;
			

		}

		private void checkWordFail()
		{
			if (Mistakes == 7)
			{
				Level = 0;
				Mistakes = 0;
				System.Windows.MessageBox.Show("Ai pierdut!");
			}
		}

		private void checkWordFinish()
		{
			int index = UndiscoveredWord.IndexOf('_');
			if(index==-1)
			{
				Level++;
				Mistakes = 0;
			}
		}
		private void nextPicture()
		{
			int imageIndex = 0;
			foreach (char c in imageSource)
			{
				if (c >= '0' && c <= '9')
				{
					imageIndex = Int32.Parse(c + "");
				}
			}

			if (imageIndex < 7)
			{
				int aux = imageIndex + 1;
				ImageSource = ReplaceAt(ImageSource, 22, 1, aux.ToString());
			}
		}

		private int mistakes = 0;
		public int Mistakes
		{
			get { return game.Mistakes; }
			set { game.Mistakes = value; OnPropertyChanged("Mistakes"); }
		}


		public string ToDiscoverWord
		{
			get { return game.ToDiscoverWord; } set { game.ToDiscoverWord = value;OnPropertyChanged("ToDiscoverWord"); }
		}




		public string Category { get { return game.Category; } set { game.Category = value; OnPropertyChanged("Category"); } }


		public string UndiscoveredWord
		{
			get { return game.UndiscoveredWord; }
			set
			{
				game.UndiscoveredWord = value;
				OnPropertyChanged("UndiscoveredWord");
			}
		}


		private string userName = "Radu";
		public string UserName { get { return userName; } set { userName = value; OnPropertyChanged("UserName"); } }


		private string imageSource = @"C:\HangmanImages\image1.jgp";
		public string ImageSource { get { return imageSource; } set { imageSource = value; OnPropertyChanged("ImageSource"); } }

		
		public int Level { get { return game.Level; } set { game.Level = value; OnPropertyChanged("Level"); } }


		private ICommand command;

		public ICommand Command
		{
			get
			{
				return command;
			}
			set
			{
				command = value;
			}
		}



	}
}
