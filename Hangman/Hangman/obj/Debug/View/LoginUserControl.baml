   M S B A M L   `   `   `  ����B  >Hangman, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null5clr-namespace:Hangman.ViewModelHangman.ViewModel  5      #    Hangman.View.LoginUserControl   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      1localclr-namespace:Hangman.ViewModel     5      $��592.115��5      $��1057.58��60     � 	Resources  5	      %  Hangman.ViewModel.UserViewModel 
  userVM �� 
TargetType �� Property �� Value��%�   &	        '��        5
      6   �� 5      " ��6
   .�5      ��  � ��
 ��  �61   �� 5       � ��$ 16(�6    6-   �� 5       � ��$ 40��6   6+   �� 5       � ��$ 50��6   6*   5      5      .��5      �  � DataContext 6   ��  �� Source# [  .+�5      �� -   5         ��Name$ listView��5      $
��Left=�6   $	��400��6:   $��	49,49,0,0q�6G   $	��Top=�6Z   $	��420��6r   ��6~   ��  �� Path$ Users���5      �� 5      .R�5      �� .+�5      �� $	��400��6-   ��6   �� $
 Name���69   ��  �� RelativeSource �� *FindAncestor+	 �� AncestorType"	 ��$$ DataContext.ImageChangeCommand���6�   �� 5      5      5      �� 5      -   5        
 ��Name$
 image��5   
   $
��Left=�6   $	��400��64   $	��Top=�6A   $	��400��6Y   $��
530,49,0,0q�6e   ��6y   �� $ 	ImagePath� �� Mode$ TwoWay=��� 5      -   5         ��Name$ newUserButton��5      $	��New��6"   $
��Left=�60   $��799,489,0,0q�6K   $	��Top=�6`   $	��131��6x   $��38��6�   ��6�   �� *NewUserCommand+�� 5       -   5        $ deleteUserButton��5       $��Delete��6%   $
��Left=�66   $��100,493,0,0q�6Q   $	��Top=�6f   $	��132��6~   $��38��6�   ��6�   �� *DeleteUserCommand+�� 5!      -   5        $ startGameButton��5!      $��
Start Game��6$   $
��Left=�69   $��284,493,0,0q�6T   $	��Top=�6i   $	��130��6�   $��38��6�   ��6�   �� *StartGameCommand+�� 5"      -   5        $ previousButton��5"      $��Previous��6#   $
��Left=�66   $��27��6Q   $��570,422,0,0q�6]   $	��Top=�6r   $	��166��6�   ��6�   �� *PreviousImageCommand+�� 5#      -   5        $ 
nextButton��5#      $
��Next��6   $
��Left=�6.   $��780,422,0,0q�6I   $	��Top=�6^   $	��166��6v   $��27��6�   ��6�   �� *NextImageCommand+�� 5$      -   5         ��Name$ textBox��5$      $
��Left=�6   $��34��68   $��570,493,0,0q�6D    �� TextWrapping$
 Wrap=�6Y   $	��Top=�6�   $	��166��6�   ��6m   �� *NewUserName+$ TwoWay=�6�   5'      5(      