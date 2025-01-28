
#include "MatamStory.h"
#include "Utilities.h"


std::shared_ptr<Monster> MatamStory::MonsterInventer(std::string &EventName, std::istream &eventsStream) {
    if (EventName=="Snail") {
        return std::make_shared<Snail>();
    }
    else if(EventName == "Slime") {
        return std::make_shared<Slime>();
    }
    else if (EventName=="Balrog"){
        return std::make_shared<Balrog>();
    }
    else if (EventName=="Pack"){
        int sizeOfPack;
        eventsStream >> sizeOfPack;
        if(sizeOfPack<2) throw std::runtime_error("Invalid Events File");
        std::shared_ptr<Pack> pack = std::make_shared<Pack>(sizeOfPack);
        string EventInPack;
        for(int i=0;i<sizeOfPack;i++){
            if (eventsStream >> EventInPack){
            }
            else{
                throw std::runtime_error("Invalid Events File");
            }
            pack->Add(MonsterInventer(EventInPack,eventsStream));
        }
        return pack;

    }
    else{
        throw std::runtime_error("Invalid Events File");
    }
}

std::shared_ptr<Event> MatamStory::EventInventer(std::string &EventName, std::istream& eventsStream) {
    if (EventName == "SolarEclipse"){
        return std::make_shared<SolarEclipse>();
    }
    else if (EventName == "PotionsMerchant"){
        return std::make_shared<PotionsMerchant>();
    }
    else return MonsterInventer(EventName,eventsStream);
}


void MatamStory::ReadEvents(std::istream &eventsStream) {

    std::string EventName;
    int count=0;
    while (eventsStream >> EventName){
        m_Events.push_back(EventInventer(EventName,eventsStream));
        count++;
    }
    if (count<2) throw std::runtime_error("Invalid Events File");
}


Job *MatamStory::CreateJob(std::string PlayerName, std::string &JobName) {
    if(JobName== "Warrior"){
        return new Warrior(PlayerName);
    }
    else if(JobName== "Archer"){
        return new Archer(PlayerName);
    }
    else if(JobName=="Magician"){
        return new Magician(PlayerName);
    }
    else {
        throw std::runtime_error("Invalid Players File");
    }
}

Character *MatamStory::CreateCharacter(std::string &CharacterName, Job *job) {
    if(CharacterName== "Responsible"){
        return new Responsible(job);
    }
    else if (CharacterName== "RiskTaking"){
        return new RiskTaking(job);
    }
    else {
        throw std::runtime_error("Invalid Players File");
    }
}


void MatamStory::ReadPlayers(std::istream &playersStream) {
    string PlayerName, JobName, CharacterName;

    while((playersStream >> PlayerName )&& (playersStream >> JobName)&& (playersStream >> CharacterName) ){
        if (PlayerName.size()<3||PlayerName.size()>15) throw std::runtime_error("Invalid Players File");
        for (char i : PlayerName) {
            if ( !isalpha(i))
                throw std::runtime_error("Invalid Players File");
        }
        m_numberOfPlayers++;
        Job* newJob = CreateJob(PlayerName ,JobName);
        Character* newCharacter= CreateCharacter(CharacterName,newJob);
        std::shared_ptr<Player> newPlayer= std::make_shared<Player>(newCharacter);
        m_AllPlayers.push_back(newPlayer);
    }
    if(m_numberOfPlayers<2||m_numberOfPlayers>6){
        throw std::runtime_error("Invalid Players File");
    }
    if (PlayerName!="" && CharacterName==""){
        throw std::runtime_error("Invalid Players File");
    }
}


MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream)
        :m_Events(),m_AllPlayers(), m_AlivePlayers(), m_CurrentPlayer(nullptr),
         m_numberOfPlayers(0) , m_turnIndex(1){


    ReadEvents(eventsStream);


    ReadPlayers(playersStream);

    vector<std::shared_ptr<Player>>::iterator it= m_AllPlayers.begin();
    while(it!= m_AllPlayers.end()){
        m_AlivePlayers.push_back(*it);
        it++;
    }
    m_CurrentPlayer = m_AlivePlayers.front();
}


void MatamStory::playTurn(Player& player) {


    const Event& event=(*m_Events.front());
    printTurnDetails(m_turnIndex,player,event);
    m_Events.front()->getDescription();
    m_Events.front()->EncounterEvent(m_CurrentPlayer);
    std::shared_ptr<Event> doneEvent= m_Events.front();
    m_Events.erase(m_Events.begin());
    m_Events.push_back(doneEvent);


    m_AlivePlayers.erase(m_AlivePlayers.begin());
    if (!m_CurrentPlayer->isKnockedOut()){
        m_AlivePlayers.push_back(m_CurrentPlayer);
    }
    if (!m_AlivePlayers.empty()){
        m_CurrentPlayer=m_AlivePlayers.front();
    } else{
        m_CurrentPlayer= nullptr;
    }

    m_turnIndex++;


}

void MatamStory::playRound() {

    printRoundStart();

    int num_of_alive = m_AlivePlayers.size();

   m_CurrentPlayer = m_AlivePlayers.front();

    for(int i = 0; i < num_of_alive; i++){
        playTurn(*m_CurrentPlayer);
    }


    printRoundEnd();

    printLeaderBoardMessage();
    printLeaderBoardByorder();


    printBarrier();
}
bool MatamStory::isGameOver() const {

    vector<std::shared_ptr<Player>>::const_iterator it= getTopPlayer(m_AllPlayers);
    if ((*it)->getLevel()==10) {
        printGameOver();
        printWinner(*(*it));
        return true;
    }

    if (m_AlivePlayers.empty()) {
        printGameOver();
        printNoWinners();
        return true;
    }
    return false;
}

void MatamStory::play() {

    printStartMessage();
    for(int i=1;i<=m_numberOfPlayers;i++){
        printStartPlayerEntry(i,*m_AllPlayers[i-1]);
    }
    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

}


vector<std::shared_ptr<Player>>::const_iterator MatamStory::getTopPlayer(const vector<std::shared_ptr<Player>> &copy) const {

    vector<std::shared_ptr<Player>>::const_iterator TopPlayerIt=copy.begin();

    for (vector<std::shared_ptr<Player>>::const_iterator it= copy.begin();it!=copy.end();it++)
    {
        if((*TopPlayerIt)->getLevel()<(*it)->getLevel()){
            TopPlayerIt=it;
        }
        else if ((*TopPlayerIt)->getLevel()> (*it)->getLevel())
        {
            continue;
        }
        else {
            if ((*TopPlayerIt)->getCoins()<(*it)->getCoins()){
                TopPlayerIt=it;
            }
            else if ((*TopPlayerIt)->getCoins()>(*it)->getCoins()){
                continue;
            }
            else{
                if((*TopPlayerIt)->getName()>(*it)->getName()){
                    TopPlayerIt=it;
                }
            }
        }
    }
    return TopPlayerIt;
}

void MatamStory::printLeaderBoardByorder() const {
    int count=0;

    vector<std::shared_ptr<Player>> copy= m_AllPlayers;
    while(!copy.empty()){
        vector<std::shared_ptr<Player>>::const_iterator TopPlayerIt= getTopPlayer(copy);
        std::shared_ptr<Player> TopPlayer= (*TopPlayerIt);
        count++;
        printLeaderBoardEntry(count, *TopPlayer);
        copy.erase(TopPlayerIt);
    }

}


