#include "Player.h"
#include <regex>

void PlayerData::inputValidation()
{
    cout << "Enter Player Name: ";
    std::regex allowedPattern("^[a-zA-Z]+$");// Matches only letters
    std::getline(std::cin, mPlayerName);

    while(std::all_of(mPlayerName.begin(), mPlayerName.end(), ::isalpha) == false)
    { 
        std::cout << "Invalid input. Please enter a Valid String : ";
        std::cin.clear();
        std::getline(std::cin, mPlayerName);
    }
}

size_t PlayerData::calculateSpareBonusScore(const size_t& frameIndex)
{
    size_t spareBonus = 0;
    if(frameIndex <= mCurrPlayerFrameData.size() && mCurrPlayerFrameData[frameIndex].getSpareFlag())
    {
        //for the frames 1 to 9 (Bonus = Next Frame -> First Try Pin Score + Second Try Pin Score)
        if((frameIndex >= 0 && frameIndex < 9))
        {
            if((frameIndex + 1 > 0 && frameIndex + 1 < 10) && (frameIndex + 1 < mCurrPlayerFrameData.size()))
            {
                size_t nextFrameBonusScore = mCurrPlayerFrameData[frameIndex + 1].getFirstTryPinScore();
                spareBonus = 10 + nextFrameBonusScore;
                mCurrPlayerFrameData[frameIndex].setSpareBonus(nextFrameBonusScore);
            }
            else
            {
                spareBonus = 10;
            }
        }
        //for the last frame i.e 10th frame (Bonus = Current Frame -> First Try Pin Score + Second Try Pin Score + Third Try Pin Score)
        else if(frameIndex == 9) 
        {
            spareBonus = mCurrPlayerFrameData[frameIndex].getFirstTryPinScore() + 
                         mCurrPlayerFrameData[frameIndex].getSecondTryPinScore() + 
                         mCurrPlayerFrameData[frameIndex].getThirdTryPinScore();

            mCurrPlayerFrameData[frameIndex].setSpareBonus(mCurrPlayerFrameData[frameIndex].getThirdTryPinScore());
        }
    }
    return spareBonus;
}

size_t PlayerData::calculateStrikeBonusScore(const size_t& frameIndex)
{
    size_t strikeBonus = 0;
    if(frameIndex <= mCurrPlayerFrameData.size() && mCurrPlayerFrameData[frameIndex].getStrikeFlag())
    {
        //for the frames 1 to 9 (Bonus = Next Frame -> First Try Pin Score + Second Try Pin Score)
        if((frameIndex >= 0 && frameIndex < 9))
        {
            if((frameIndex + 1 > 0 && frameIndex + 1 < 10) && (frameIndex + 1 < mCurrPlayerFrameData.size()))
            {
                size_t nextFrameBonusScore = mCurrPlayerFrameData[frameIndex + 1].getFirstTryPinScore() + 
                                             mCurrPlayerFrameData[frameIndex + 1].getSecondTryPinScore();
                strikeBonus = 10 + nextFrameBonusScore;
                mCurrPlayerFrameData[frameIndex].setStrikeBonus(nextFrameBonusScore);
                
            }
            else
            {
                strikeBonus = 10;
            }
        }
        //for the last frame i.e 10th frame (Bonus = Current Frame -> First Try Pin Score + Second Try Pin Score + Third Try Pin Score)
        else if(frameIndex == 9)
        {
            strikeBonus = mCurrPlayerFrameData[frameIndex].getFirstTryPinScore() + 
                         mCurrPlayerFrameData[frameIndex].getSecondTryPinScore() + 
                         mCurrPlayerFrameData[frameIndex].getThirdTryPinScore();

            mCurrPlayerFrameData[frameIndex].setStrikeBonus(mCurrPlayerFrameData[frameIndex].getThirdTryPinScore());
        }
    }
    return strikeBonus;
}

PlayerData::PlayerData(string _playerName)
:mPlayerName(_playerName)
{
    if(_playerName.length() == 0)
        inputValidation();
    
    if(isDebugEnabled())
        cout<<"Player Data Constrcution " << endl;
}

void PlayerData::addFrameData(const FrameData& _currPlayerFrameData)
{
    mCurrPlayerFrameData.emplace_back(FrameData(_currPlayerFrameData));
    
    if(mCurrPlayerFrameData.size() > MAX_FRAME_SIZE)
        throw GameException("Caught Game Rule Exception : More then 10 Frames are Not Allowed...!");
}

const size_t& PlayerData::getPrevFrameScore(const size_t& prevFrameID) const
{
    return mCurrPlayerFrameData[prevFrameID].getCurrentFrameScore();
}

const vector<FrameData>& PlayerData::getCurrentPlayerFrameData()
{
    return mCurrPlayerFrameData;
}

string PlayerData::getPlayerName() const 
{
    return mPlayerName;
}

void PlayerData::calculatePerFramePlayerScore()
{
    if(!mCurrPlayerFrameData.empty())
    {
        for (auto &&currFrameData : mCurrPlayerFrameData)
        {
            size_t frameScore = 0;
            //Case I : When there is No Spare & No Strike for the Current Frame.
            if( currFrameData.getSpareFlag() == false && currFrameData.getStrikeFlag() == false )
            {
                if(currFrameData.getFrameID() == 0)
                {
                    frameScore = currFrameData.getFirstTryPinScore() + currFrameData.getSecondTryPinScore();
                }
                else
                {
                    frameScore = getPrevFrameScore(currFrameData.getFrameID() - 1) + currFrameData.getFirstTryPinScore() + currFrameData.getSecondTryPinScore();
                }

                currFrameData.setCurrentFrameScore(frameScore);
            }
            //Case II : When there is a Spare for the Current Frame & Required Additional Bonus Score Addition.
            else if( currFrameData.getSpareFlag() == true )
            {
                if(currFrameData.getFrameID() == 0)
                {
                    frameScore = calculateSpareBonusScore(currFrameData.getFrameID());
                }
                else 
                {
                    frameScore = getPrevFrameScore(currFrameData.getFrameID() - 1) + calculateSpareBonusScore(currFrameData.getFrameID());
                }

                currFrameData.setCurrentFrameScore(frameScore);
            }
            //Case III : When there is a Strike for the Current Frame & Required Additional Bonus Score Addition.
            else if( currFrameData.getStrikeFlag() == true )
            {
                if(currFrameData.getFrameID() == 0)
                {
                    frameScore = calculateStrikeBonusScore(currFrameData.getFrameID());
                }
                else 
                {
                    frameScore = getPrevFrameScore(currFrameData.getFrameID() -1) + calculateStrikeBonusScore(currFrameData.getFrameID());
                }
                currFrameData.setCurrentFrameScore(frameScore);
            }
            else
            {
                cout<<"Any Scenrio is Missed?..." << endl;
            }
        }
    }
    else
    {
        cout<<"Run Time Exception - Frame Data for the Player " << mPlayerName << " is Empty " << endl;
    }
}

PlayerData::~PlayerData()
{
    if(isDebugEnabled())
        cout<<"Player Data Destruction" << endl;
}