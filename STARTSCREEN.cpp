#include "STARTSCREEN.h"

void Startscreen() {
    // Make the window
    RenderWindow start_window(VideoMode(Startscreen_Col, Startscreen_Row), "MINESWEEPER");

    // Create background
    Texture StartBg;
    StartBg.loadFromFile("IMAGE/STARTBG.jpg");
    Sprite StartBg_Sprite;
    StartBg_Sprite.setTexture(StartBg);

    // NewGame Image
    Texture NewGame;
    NewGame.loadFromFile("IMAGE/NEWGAME.png");
    ButtonClass NewGame_Button;
    NewGame_Button = ButtonClass(Vector2f(Button_Col, Button_Row), Vector2f(300, 200), NewGame);

    // LoadGame Image
    Texture LoadGame;
    LoadGame.loadFromFile("IMAGE/LOADGAME.png");
    ButtonClass LoadGame_Button(Vector2f(Button_Col, Button_Row), Vector2f(300, 280), LoadGame);

    // LeaderBoard
    Texture LeaderBoard;
    LeaderBoard.loadFromFile("IMAGE/LEADERBOARD.png");
    ButtonClass LeaderBoard_Button(Vector2f(Button_Col, Button_Row), Vector2f(300, 360), LeaderBoard);

    // Instruction
    Texture Instruction;
    Instruction.loadFromFile("IMAGE/INSTRUCTION.png");
    ButtonClass Instruction_Button(Vector2f(Button_Col, Button_Row), Vector2f(300, 440), Instruction);

    // Author
    Texture Author;
    Author.loadFromFile("IMAGE/AUTHOR.png");
    ButtonClass Author_Button(Vector2f(Button_Col, Button_Row), Vector2f(300, 520), Author);

    while(start_window.isOpen()) {
        Event event;

        // Close the window
        while(start_window.pollEvent(event)) {
            if(event.type == Event::Closed) {
                start_window.close();
            }
        }

        start_window.clear(Color::Black);

        // Draw here

        //Make_Background;
        start_window.draw(StartBg_Sprite);

        // Make NewGame button
        start_window.draw(NewGame_Button.Rect);

        // Make LoadGame button
        start_window.draw(LoadGame_Button.Rect);

        // MAKE LeaderBoard
        start_window.draw(LeaderBoard_Button.Rect);

        // MAKE INSTRUCTION
        start_window.draw(Instruction_Button.Rect);

        // Make Author
        start_window.draw(Author_Button.Rect);

        Vector2f Position = start_window.mapPixelToCoords(Mouse::getPosition(start_window));

        // Into NewGame Button
        int val = NewGame_Button.is_Clicked(Position);
        if(val == 1) {
            start_window.close();
            Select_Difficulty_Screen();
        }

        if(val == 2) NewGame_Button.Rect.setFillColor(Color::Green);
        if(val == 0) NewGame_Button.Rect.setFillColor(Color::White);

        // Into LoadGame Button
        int LoadGame_val = LoadGame_Button.is_Clicked(Position);
        if(LoadGame_val == 1) {
            ifstream fin;
            fin.open("GAME_STATE.txt");

            int type; fin >> type;
            fin.close();

            if(type != -1) {
                start_window.close();
                NewGame_Screen();
            }
        }
        if(LoadGame_val == 2) LoadGame_Button.Rect.setFillColor(Color::Green);
        if(LoadGame_val == 0) LoadGame_Button.Rect.setFillColor(Color::White);

        // Into LeaderBoard Button
        int LeaderBoard_val = LeaderBoard_Button.is_Clicked(Position);
        if(LeaderBoard_val == 1) {
            start_window.close();
            LeaderBoard_Screen();
        }
        if(LeaderBoard_val == 2) LeaderBoard_Button.Rect.setFillColor(Color::Green);
        if(LeaderBoard_val == 0) LeaderBoard_Button.Rect.setFillColor(Color::White);

        // Into Instruction Button
        int Instruction_val = Instruction_Button.is_Clicked(Position);
        if(Instruction_val == 1) {
            start_window.close();
            Instruction_Screen();
        }
        if(Instruction_val == 2) Instruction_Button.Rect.setFillColor(Color::Green);
        if(Instruction_val == 0) Instruction_Button.Rect.setFillColor(Color::White);

        // Into Author Button
        int Author_val = Author_Button.is_Clicked(Position);
        if(Author_val == 1) {
            start_window.close();
            Author_Screen();
        }
        if(Author_val == 2) Author_Button.Rect.setFillColor(Color::Green);
        if(Author_val == 0) Author_Button.Rect.setFillColor(Color::White);

        // Display
        start_window.display();
    }
}
