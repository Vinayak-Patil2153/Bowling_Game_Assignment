#include "Exception.h"
#include<iostream>
#include <limits>
using namespace std;

#define MAX_FRAME_SIZE 10

extern bool isDebugEnabled();

class FrameData
{
    size_t mCurrentFrameIndex;
    size_t mFirstTryPinScore;
    size_t mSecondTryPinScore;
    size_t mThirdTryPinScore;
    bool mIsSpare;
    bool mIsStrike;
    size_t mCurrentFrameScore;
    size_t mSpareBonus;
    size_t mStrikeBonus;

    void inputValidation(size_t& _pinScore);
    void validateInputPinScore();
    
public: 
    FrameData(  size_t _currentFrameIndex = 0,
                size_t _firstTryPinScore = 0,
                size_t _secondTryPinScore = 0,
                size_t _thirdTryPinScore = 0,
                bool _isSpare = false,
                bool _isStrike = false,
                size_t _currentFrameScore = 0,
                size_t _spareBonus = 0,
                size_t _strikeBonus = 0);

    void setFrameID(const size_t& _frameID);
    const size_t& getFrameID() const;

    void setFirstTryPinScore(size_t _firstTryPinScore);
    const size_t& getFirstTryPinScore() const;

    void setSecondTryPinScore(size_t _secondTryPinScore);
    const size_t& getSecondTryPinScore() const;
    
    void setThirdTryPinScore(size_t _ThirdTryPinScore);
    const size_t& getThirdTryPinScore() const;
    
    void setSpareFlag(bool _isSpareFlag);
    const bool& getSpareFlag() const;

    void setStrikeFlag(bool _isStrikeFlag);
    const bool& getStrikeFlag() const;
    
    void setCurrentFrameScore(size_t _currentFrameScore);
    const size_t& getCurrentFrameScore() const;

    void setSpareBonus(size_t _spareBonus);
    const size_t& getSpareBonus() const;

    void setStrikeBonus(size_t _strikeBonus);
    const size_t& getStrikeBonus() const;

    const size_t  getPrevFrameIndex() const;

    void inputDataValidation(const size_t& currentFrameDataIndex);

    ~FrameData();
};