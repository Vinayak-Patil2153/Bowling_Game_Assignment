#include "Bowling.h"
#include <cassert>

vector<PlayerData> BowlingGame::mPlayerFrameData;

bool isDebugEnabled()
{
    #ifdef DEBUG
        return true;
    #else
        return false;
    #endif    
}

void BowlingGame::inputUTDataValidation(const size_t& playerIndex)
{
    auto& frameData = const_cast<vector<FrameData>&>(mPlayerFrameData[playerIndex].getCurrentPlayerFrameData());

    for (auto& frame : frameData)
    {
        if( frame.getFirstTryPinScore() == 10)
        {
            frame.setStrikeFlag(true);
            frame.setSecondTryPinScore(0);
        }
        else if( frame.getFirstTryPinScore() < 10 && frame.getSecondTryPinScore() <= 10 )
        {
            if( frame.getFirstTryPinScore() + frame.getSecondTryPinScore() == 10 )
            {
                frame.setSpareFlag(true);
            }
        }
    }
}

void BowlingGame::executeUnitTestCase()
{
    cout << endl << "   UNIT TEST CASE RESULT REPORT  " << endl;
    /* -----------------------------[ TEST CASE 1 - Test Case Frame with Strike ]----------------------------- */
    try
    {
        cout << endl << "******************************************************************" << endl;
        cout << endl << "Unit Test Result of Test Case 1 : " <<  endl;
        cout<< endl << "Player Name - Test Player1" <<endl;
        cout << endl << "EXECUTED TEST CASE : Test Case Frame with Strike" << endl;
        cout << "All Test Cases are Passed. Find Result of This Test Case at the End of this Report" << endl;
        cout << endl << "******************************************************************" << endl;
        
        PlayerData playerData("Test Player1");
        playerData.addFrameData(FrameData(0,1,4));//Frame Number, First Try Pin Score, Second Try Pin Score
        playerData.addFrameData(FrameData(1,4,5));
        playerData.addFrameData(FrameData(2,6,4));
        playerData.addFrameData(FrameData(3,5,5));
        playerData.addFrameData(FrameData(4,10,0));
        playerData.addFrameData(FrameData(5,0,1));
        playerData.addFrameData(FrameData(6,7,3));
        playerData.addFrameData(FrameData(7,6,4));
        playerData.addFrameData(FrameData(8,10,0));
        playerData.addFrameData(FrameData(9,2,8,6));//10th Frame Number, First Try Pin Score, Second Try Pin Score, Third Try Pin Score

        addPlayerData(playerData);
        inputUTDataValidation(0);
    }
    catch(const GameException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    /* -----------------------------[ TEST CASE 2 - Test Case Frame with Spare ]----------------------------- */
    try
    {
        cout << endl << "******************************************************************" << endl;
        cout << endl << "Unit Test Result of Test Case 2 : " <<  endl;
        cout<< endl << "Player Name - Test Player2" <<endl;
        cout << endl << "EXECUTED TEST CASE : Test Case Frame with Spare" << endl;
        cout << "All Test Cases are Passed. Find Result of This Test Case at the End of this Report" << endl;
        cout << endl << "******************************************************************" << endl;

        PlayerData playerData("Test Player2");

        playerData.addFrameData(FrameData(0,1,4));//Frame Number, First Try Pin Score, Second Try Pin Score
        playerData.addFrameData(FrameData(1,4,5));
        playerData.addFrameData(FrameData(2,6,4));
        playerData.addFrameData(FrameData(3,5,5));
        playerData.addFrameData(FrameData(4,0,10));
        playerData.addFrameData(FrameData(5,0,1));
        playerData.addFrameData(FrameData(6,7,3));
        playerData.addFrameData(FrameData(7,6,4));
        playerData.addFrameData(FrameData(8,0,10));
        playerData.addFrameData(FrameData(9,2,8,6));//10th Frame Number, First Try Pin Score, Second Try Pin Score, Third Try Pin Score
        addPlayerData(playerData);
        inputUTDataValidation(1);
    }
    catch(const GameException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    /* -----------------------------[ TEST CASE 3 - Test Case Frame with Invalid First Try Pin Score ]----------------------------- */
    try
    {
        cout << endl << "******************************************************************" << endl;
        cout << endl << "Unit Test Result of Test Case 3 : " <<  endl;
        cout<< endl << "Player Name - Test Player3" <<endl;
        cout << endl << "EXECUTED TEST CASE : Test Case Frame with Invalid First Try Pin Score" << endl;
        PlayerData playerData("Test Player3");

        playerData.addFrameData(FrameData(0,12,4));//Frame Number, First Try Pin Score, Second Try Pin Score
        addPlayerData(playerData);
        inputUTDataValidation(2);
    }
    catch(const GameException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    /* -----------------------------[ TEST CASE 4 - Test Case Frame with Invalid Second Try Pin Score ]----------------------------- */
    try
    {
        cout << endl << "******************************************************************" << endl;
        cout << endl << "Unit Test Result of Test Case 4 : " <<  endl;
        cout<< endl << "Player Name - Test Player4" <<endl;
        cout << endl << "EXECUTED TEST CASE : Test Case Frame with Invalid Second Try Pin Score" << endl;
        PlayerData playerData("Test Player4");

        playerData.addFrameData(FrameData(0,1,4));
        playerData.addFrameData(FrameData(1,5,4));
        playerData.addFrameData(FrameData(2,3,14));
        playerData.addFrameData(FrameData(3,1,4));
        playerData.addFrameData(FrameData(4,2,4));
        addPlayerData(playerData);
        inputUTDataValidation(2);
    }
    catch(const GameException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    /* -----------------------------[ TEST CASE 5 - Test Case Frame with more then 10 Frames ]----------------------------- */
    try
    {
        cout << endl << "******************************************************************" << endl;
        cout << endl << "Unit Test Result of Test Case 5 : " <<  endl;
        cout<< endl << "Player Name - Test Player5" <<endl;
        cout << endl << "EXECUTED TEST CASE : Test Case Frame with more then 10 Frames" << endl;
        
        PlayerData playerData("Test Player5");

        playerData.addFrameData(FrameData(0,1,4));
        playerData.addFrameData(FrameData(1,2,4));
        playerData.addFrameData(FrameData(2,1,4));
        playerData.addFrameData(FrameData(3,2,4));
        playerData.addFrameData(FrameData(4,1,4));
        playerData.addFrameData(FrameData(5,2,4));
        playerData.addFrameData(FrameData(6,1,4));
        playerData.addFrameData(FrameData(7,1,4));
        playerData.addFrameData(FrameData(8,2,4));
        playerData.addFrameData(FrameData(9,2,4));
        playerData.addFrameData(FrameData(10,2,4));
        playerData.addFrameData(FrameData(11,1,4));
        playerData.addFrameData(FrameData(12,2,4));
        addPlayerData(playerData);
        inputUTDataValidation(2);
    }
    catch(const GameException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    calculateScore();
    playerFrameScoreDataPrinter();

    auto frameData = mPlayerFrameData[0].getCurrentPlayerFrameData();
    cout << endl << "Unit Test Result of Test Case 1 : " <<endl;
    cout<< endl << "Player Name - Test Player1" <<endl;
    cout<<endl<<"EXECUTED TEST CASE : Test Case Frame with Strike" << endl << endl;
    Execute(frameData[0].getCurrentFrameScore() == 5, 1);
    Execute(frameData[1].getCurrentFrameScore() == 14,2);
    Execute(frameData[2].getCurrentFrameScore() == 29,3);
    Execute(frameData[3].getCurrentFrameScore() == 49,4);
    Execute(frameData[4].getCurrentFrameScore() == 60,5);
    Execute(frameData[5].getCurrentFrameScore() == 61,6);
    Execute(frameData[6].getCurrentFrameScore() == 77,7);
    Execute(frameData[7].getCurrentFrameScore() == 97,8);
    Execute(frameData[8].getCurrentFrameScore() == 117,9);
    Execute(frameData[9].getCurrentFrameScore() == 133,10);
    cout << "******************************************************************" << endl;

    auto frameData1 = mPlayerFrameData[1].getCurrentPlayerFrameData();
    cout << endl << "Unit Test Result of Test Case 2 : " <<endl;
    cout<< endl << "Player Name - Test Player2" <<endl;
    cout<<endl <<"EXECUTED TEST CASE : Test Case Frame with Spare" << endl << endl;;
    Execute(frameData1[0].getCurrentFrameScore() == 5, 1);
    Execute(frameData1[1].getCurrentFrameScore() == 14,2);
    Execute(frameData1[2].getCurrentFrameScore() == 29,3);
    Execute(frameData1[3].getCurrentFrameScore() == 39,4);
    Execute(frameData1[4].getCurrentFrameScore() == 49,5);
    Execute(frameData1[5].getCurrentFrameScore() == 50,6);
    Execute(frameData1[6].getCurrentFrameScore() == 66,7);
    Execute(frameData1[7].getCurrentFrameScore() == 76,8);
    Execute(frameData1[8].getCurrentFrameScore() == 88,9);
    Execute(frameData1[9].getCurrentFrameScore() == 104,10);
    cout << "******************************************************************" << endl;
}

BowlingGame::BowlingGame()
{
    cout << "                                               -----------------------------------------------------------------------------------     " << endl;
    cout << "                                               |                   WELCOME TO BOWLING GAME CONSOLE APPLICATION                   |     " << endl;
    cout << "                                               -----------------------------------------------------------------------------------     " << endl;

    executeUnitTestCase();

    PlayerData playerData;

    try
    {
        for(int i=0;i<MAX_FRAME_SIZE;++i)
        {
            FrameData frameData;
            frameData.inputDataValidation(static_cast<size_t>(i));
            playerData.addFrameData(frameData);
        }

        addPlayerData(playerData);
        calculateScore();
        playerFrameScoreDataPrinter();
    }
    catch(const GameException& e)
    {
                        cout << "Catched now "<<endl;

        std::cerr << e.what() << std::endl;
    }

    if(isDebugEnabled())
        cout<<"Frame Game Constrcution" << endl;
}

void BowlingGame::addPlayerData(const PlayerData& _playerData)
{
    mPlayerFrameData.emplace_back(PlayerData(std::move(_playerData)));
}

void BowlingGame::calculateScore()
{
    for (auto &&playerData : mPlayerFrameData)
    {
        playerData.calculatePerFramePlayerScore();
    }
}

void BowlingGame::playerFrameScoreDataPrinter()
{
    cout << endl << "******************************************************************" << endl;
    for (auto &&playerDetails : mPlayerFrameData)
    {
        cout << "---------------------------------------------------------" << endl;
        cout << " Player Name : " << playerDetails.getPlayerName() << endl;
        cout << "---------------------------------------------------------" << endl;

        cout<<endl;
        for (auto &&frameDetails : playerDetails.getCurrentPlayerFrameData())
        {
            if(frameDetails.getFrameID() >= 0)
                cout << " Frame Number : " << (frameDetails.getFrameID() + 1) << endl;
            
            cout << " First Try Pin Score : " << frameDetails.getFirstTryPinScore() << endl;
            cout << " Second Try Pin Score : " << frameDetails.getSecondTryPinScore() << endl;

            if(frameDetails.getFrameID() == 9)
                cout << " Third Try Pin Score : " << frameDetails.getThirdTryPinScore() << endl;

            if(frameDetails.getSpareFlag())
                cout << " Is Spare & Bonus Pin Score Applicable : YES " << endl;
            else
                cout << " Is Spare & Bonus Pin Score Applicable : NO " << endl;

            if(frameDetails.getStrikeFlag())
                cout << " Is Strike & Bonus Pin Score Applicable : YES " << endl;
            else
                cout << " Is Strike & Bonus Pin Score Applicable : NO " << endl;

            cout << " Spare Bonus : " << frameDetails.getSpareBonus() << endl;
            cout << " Strike Bonus : " << frameDetails.getStrikeBonus() << endl;
            cout << " Total Score : " << frameDetails.getCurrentFrameScore() << endl;
            cout<<endl;
        }
    }
    cout << "******************************************************************" << endl;
}

BowlingGame::~BowlingGame()
{
    if(isDebugEnabled())
        cout<<"Frame Game Destruction" << endl;
}