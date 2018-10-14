Hello and welcome to PIANOOO IMAC,

The project was made on Codeblocks so i have included the project folder
but i have also the Makefile in order to be able to compile and execute
the program without necessarly using Codeblocks.

This is a music console application, currently it has only piano but later
i can add other instruments since the program is based on a MusInstrument 
class from which i derive the different instruments classes.


Once you launch the application, the menu allows you to add a new user(create
a new folder that will be later used to stock the different songs you will record)
or if you are already a user (it uses your folder).  

In each folder you can find your songs in different txt files that you can load
on the application to listen to.

All the users folders are included in the "Users" folder.

(You can use the username "amel" and load one of the files to test or create your own one...)

Once the piano interface is loaded, you can do this different options:
To record, you press 5 to start recording and 5 again to stop the record.
To load, you press 8 and then you type the name of the song you want to load.
+/- allows you to go an octave up or down.
9 allows you to change the press duration.
different keys are used to play on the piano
(ALL THIS INFORMATIONS ARE INDICATED ON THE APPLICATION INTERFACE).
(YOU CAN ALSO ACESS THE TUTORIAL FROM THE MAIN MENU).
-------------------------------------------------------------------------------------------
CLASS NAME   	 | DESCRIPTION								  |
------------------------------------------------------------------------------------------|
Menu		 | Manages menu.							  |
MusInstrument	 | Manages the main loop of the application/ save/load/Keys handeling..   |
		 | Basically the common things between all instruments.			  |
Piano		 | Manages the piano notes (specific to the piano instrument).		  |
PianoAppException| Template class that derives from std::exceptions.			  | 
		 | Allows to manage different exception of application (no matter 	  |
		 | the type : string, int ... the reason why i made it a template).	  |
FolderException	 | Manages the folder creation exceptions, derives from PianoAppException.|
FileException    | Manages the file creation exceptions, derives from PianoAppException.  |			
-------------------------------------------------------------------------------------------

					THANK YOU |ENJOY THE APP!
					      AMEL NEGRA

