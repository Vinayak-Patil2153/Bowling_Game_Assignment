#include "Frame.h"
#include<vector>

class PlayerData
{
    string mPlayerName;
    vector<FrameData> mCurrPlayerFrameData;

    void inputValidation();
    size_t calculateSpareBonusScore(const size_t& frameIndex);
    size_t calculateStrikeBonusScore(const size_t& frameIndex);
public :
    PlayerData(string _playerName = "");

    void addFrameData(const FrameData& _frameData);

    void calculatePerFramePlayerScore();

    string getPlayerName() const;

    const size_t& getPrevFrameScore(const size_t& prevFrameID) const;

    const vector<FrameData>& getCurrentPlayerFrameData();

    ~PlayerData();
};  