#include "Player.h"

#define BowlingGameStart main

#define Execute(result,frame) \
        { if (!(result)) cout << "Test Case Failed For Frame " << frame << endl; \
          else cout << "Test Case Passed For Frame " << frame << endl;}

class BowlingGame
{
    static vector<PlayerData> mPlayerFrameData;

    void inputUTDataValidation(const size_t& playerIndex);

    void executeUnitTestCase();
    
public:
    BowlingGame();

    void addPlayerData(const PlayerData& _playerData);

    void playerFrameScoreDataPrinter();

    void calculateScore();

    ~BowlingGame();
};