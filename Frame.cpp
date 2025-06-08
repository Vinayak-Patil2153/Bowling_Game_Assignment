#include "Frame.h"

void FrameData::validateInputPinScore()
{
    if( mFirstTryPinScore < 0 || mFirstTryPinScore > 10 )
        throw GameException("Caught Game Rule Exception : First Try Input Pin Score More then 10...!");
    
    if( mSecondTryPinScore > 10 )
        throw GameException("Caught Game Rule Exception : Second Try Input Pin Score More then 10...!");
    
    if( mFirstTryPinScore + mSecondTryPinScore > 10 )
        throw GameException("Caught Game Rule Exception : First & Second(First Score + Second Score) Try Input Pin Score More then 10...!");
}

void FrameData::inputValidation(size_t& _pinScore)
{
    if(&_pinScore == &mFirstTryPinScore)
    {
        std::cout << "Enter a Pin Score For First Try Between 0 to 10: ";
    }
    else if(&_pinScore == &mSecondTryPinScore)
    {
        if(( mFirstTryPinScore + mSecondTryPinScore) > 10 )
            std::cout << "First Try & Second Try Pin Score Exceeded 10..." << endl;

            std::cout << "Enter a Pin Score For Second Try Between 0 to 10: ";
    }
    else if(&_pinScore == &mThirdTryPinScore)
    {
        std::cout << "Enter a Pin Score For Third Try Between 0 to 10: ";
    }
        
    while (!(std::cin >> _pinScore)) 
    {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

FrameData::FrameData( size_t _currentFrameIndex,
            size_t _firstTryPinScore,
            size_t _secondTryPinScore,
            size_t _thirdTryPinScore,
            bool _isSpare,
            bool _isStrike,
            size_t _currentFrameScore,
            size_t _spareBonus,
            size_t _strikeBonus)
: mCurrentFrameIndex(_currentFrameIndex),
mFirstTryPinScore(_firstTryPinScore),
mSecondTryPinScore(_secondTryPinScore),
mThirdTryPinScore(_thirdTryPinScore),
mIsSpare(_isSpare),
mIsStrike(_isStrike),
mCurrentFrameScore(_currentFrameScore),
mSpareBonus(_spareBonus),
mStrikeBonus(_strikeBonus)
{
    validateInputPinScore();

    if(isDebugEnabled())
        cout<<"Frame Data Constrcution" << endl;

}

void FrameData::setFrameID(const size_t& _frameID)
{
    mCurrentFrameIndex = _frameID;
}

const size_t& FrameData::getFrameID() const
{
    return mCurrentFrameIndex;
}

void FrameData::setFirstTryPinScore(size_t _firstTryPinScore)
{
    mFirstTryPinScore = _firstTryPinScore;
}

const size_t& FrameData::getFirstTryPinScore() const
{
    return mFirstTryPinScore;
}

void FrameData::setSecondTryPinScore(size_t _secondTryPinScore)
{
    mSecondTryPinScore = _secondTryPinScore;
}

const size_t& FrameData::getSecondTryPinScore() const
{
    return mSecondTryPinScore;
}
    
void FrameData::setThirdTryPinScore(size_t _ThirdTryPinScore)
{
    mThirdTryPinScore = _ThirdTryPinScore;
}

const size_t& FrameData::getThirdTryPinScore() const
{
    return mThirdTryPinScore;
}

void FrameData::setSpareFlag(bool _isSpareFlag)
{
    mIsSpare = _isSpareFlag;
}

const bool& FrameData::getSpareFlag() const
{
    return mIsSpare;
}

void FrameData::setStrikeFlag(bool _isStrikeFlag)
{
    mIsStrike = _isStrikeFlag;
}

const bool& FrameData::getStrikeFlag() const
{
    return mIsStrike;
}

void FrameData::setCurrentFrameScore(size_t _currentFrameScore)
{
    mCurrentFrameScore = _currentFrameScore;
}

const size_t& FrameData::getCurrentFrameScore() const
{
    return mCurrentFrameScore;
}

void FrameData::setSpareBonus(size_t _spareBonus)
{
    mSpareBonus = _spareBonus;
}

const size_t& FrameData::getSpareBonus() const
{
    return mSpareBonus;
}

void FrameData::setStrikeBonus(size_t _strikeBonus)
{
    mStrikeBonus = _strikeBonus;
}

const size_t& FrameData::getStrikeBonus() const
{
    return mStrikeBonus;
}

const size_t FrameData::getPrevFrameIndex() const
{
    return (mCurrentFrameIndex - 1);
}

void FrameData::inputDataValidation(const size_t& currentFrameDataIndex)
{
    setFrameID(currentFrameDataIndex);

    cout<<"Frame Number : " << currentFrameDataIndex + 1 << endl;
    //If First Input is 10 then its Strike
    inputValidation(mFirstTryPinScore);
    validateInputPinScore();
    if( mFirstTryPinScore == 10)
        setStrikeFlag(true);
    
    //If First + Second Input is 10 then its Spare
    inputValidation(mSecondTryPinScore);
    validateInputPinScore();
    if( mFirstTryPinScore == 10)
    {
        setStrikeFlag(true);
        setSecondTryPinScore(0);
    }
    else if( mFirstTryPinScore < 10 && mSecondTryPinScore <= 10 )
    {
        if( mFirstTryPinScore + mSecondTryPinScore == 10 )
        {
            setSpareFlag(true);
        }
    }

    //If Last Frame then Only Third Try Allowed if Strike OR Spare is Achieved
    if( getFrameID() == 9 && ( getSpareFlag() || getStrikeFlag() ))
    {
        inputValidation(mThirdTryPinScore);
    }
}

FrameData::~FrameData()
{
    if(isDebugEnabled())
        cout<<"Frame Data Destruction" << endl;
}