#include<bits/stdc++.h>
using namespace std;


int n , m;

int randomGen(int lower, int upper) 
{ 
    srand(time(0) + rand());   
    int num = rand()%(upper - lower + 1) + lower; 

    return num;
} 



enum EventType
{
    Track = 1,    
    Field = 2
};


enum Award
{
    Gold = 1,
    Silver = 2,
    Bronze = 3
};

class Weather
{
    private:

        map<int, string> wthrMap;
        float impact_value;
        string wthrName;

    public:

        Weather()
        {   
            wthrMap.insert({1 , "rainy"});
            wthrMap.insert({2 , "sunny"});
            wthrMap.insert({3 , "windy"});
            wthrMap.insert({4 , "cloudy"});
            wthrMap.insert({5 , "foggy"});

            int x = randomGen(1 ,5);
            wthrName = wthrMap[x];
            setImpactValue();
        }

        void setImpactValue()
        {
            this->impact_value = randomGen(1,2);
        }

        float getImpactValue()
        {
            return impact_value;
        }

        string getWhtrName()
        {
            return wthrName;
        }

       

};

class Location
{
    private:
        string name;
        Weather wthr;
        float special_feature_value;

    public:

        Location(string name , Weather wthr )
        {
            this->name = name;
            this->wthr = wthr;

            genSpecialFeatureValue();
        }
       

        string getLocation()
        {
            return this->name;
        }

        void genSpecialFeatureValue()
        {
            this->special_feature_value = randomGen(1,2);
        }

        float locationEffect()
        {
            return special_feature_value*0.5 +  wthr.getImpactValue()*0.2;
        }    

        Weather getWhtr()
        {
            return this->wthr;
        }

};

class Person 
{
    protected:

        string name;
        char gender;
        string role;

    public:

        string getName()
        {
            return name;
        }

        char getGender()
        {
            return gender;
        }

        string getRole()
        {
            return role;
        }
};


class Athlete : public Person
{
    private:

        float readiness;
        float strength;
        float recovery_rate;
        bool injured;
        float performance_score;
        vector<Award> awards;
     
    public:

        Athlete()
        {

        }

        Athlete(string name , char gender , string role)
        {
            this->name = name;
            this->gender = gender;
            this->role = role;
        }

        bool isInjured()
        {
            return injured;
        }

        
        void initAthlete()
        {
            this->readiness = randomGen(5 ,10);
            this->strength = randomGen(5, 10);
            this->recovery_rate = randomGen(1,2) ;
            this->injured = false;
            this->performance_score = 0;
        }

        void markInjured()
        {
            injured = true;
        }

        void giveAward(Award awd)
        {
            awards.push_back(awd);
        }

        float getReadiness()
        {
            return readiness;
        }

        float getStrength()
        {
            return strength;
        }

        float getRecoveryRate()
        {
            return recovery_rate;
        }

        void setReadiness(float readiness)
        {
            this->readiness = readiness;
        }

        void setStrength(float strength)
        {
            this->strength = strength;
        }

        void setRecoveryrate(float recovery_rate)
        {
            this->recovery_rate  = recovery_rate;
        }

        
};

bool cmp(pair<int , Athlete> p1 , pair<int , Athlete> p2)
{
    return p1.first<p2.first;
}

class Physiotherapist : public Person
{
    private : 
        float recovery_capabilities;

    public:
        void recoverAthelete(Athlete ath)
        {
            float x =  ath.getRecoveryRate() + recovery_capabilities*0.1;
            ath.setRecoveryrate(x);
        }

        void setRecoverValue()
        {
            this->recovery_capabilities = randomGen(1,5);
        }

        float getRecoverValue()
        {
            return recovery_capabilities;
        }

};


class Psychologist : public Person
{
    private:
        float handle_capabilities;

    public:
        void handleAthlete(Athlete ath)
        {
            float x  = ath.getRecoveryRate() + handle_capabilities*0.1;
            ath.setRecoveryrate(x);
        }

        void setHandleCapab()
        {
            this->handle_capabilities = randomGen(1,4);
        }

        float getHandleCapab()
        {
            return handle_capabilities;
        }
};

class Trainer : public Person
{
    public:
        EventType field_specialized;
        float consistency_value;
        float improvement_rate;


        void trainAthelete(Athlete ath )
        {            
            float x = ath.getStrength() + (consistency_value*improvement_rate)*0.1;
            ath.setStrength(x);

            float y = ath.getReadiness() + (consistency_value*improvement_rate)*0.2;
            ath.setReadiness(y);
        }

        void initTrainer(EventType field_specialized)
        {
            this->field_specialized = field_specialized;
            this->consistency_value = randomGen(1,3);
            this->improvement_rate = randomGen(1,3);

        }
};

class SupportCrew
{
    private:
        Physiotherapist phy;
        Psychologist psy;
        Trainer track_trainer;
        Trainer field_trainer;

    public:
        void initSupportCrew(Physiotherapist phy , Psychologist psy , Trainer track_trainer , Trainer field_trainer)
        {
            this->phy = phy;
            this->psy = psy;
            this->track_trainer = track_trainer;
            this->field_trainer = field_trainer;
        }

        float get_phy_value()
        {
            return phy.getRecoverValue();
        }

        float get_psy_value()
        {
            return psy.getHandleCapab();
        }

};


class Team
{   
    private:
        string name;
        Athlete athlete_male;
        Athlete athlete_female;
        SupportCrew support_team;

    public:

        void addAthlete(Athlete athlete_male , Athlete athlete_female)
        {
            this->athlete_male = athlete_male;
            this->athlete_female = athlete_female;
        }

        void addSupportCrew(SupportCrew support_team)
        {
            this->support_team = support_team;
        }

        void nameTeam(string name)
        {
            this->name = name;
        }

        Athlete getMaleAth()
        {
            return athlete_male;
        }

        Athlete getFemaleAth()
        {
            return athlete_female;
        }
};


class Event
{
    private:

        string event_name;
        EventType event_type;
        float A;
        float B;
        float C;

    public:
        Event(string event_name  , EventType event_type , float A , float B , float C)
        {
            this->event_name = event_name;
            this->event_type = event_type;
            this->A = A;
            this->B = B;
            this->C = C;
        }

        float getA()
        {
            return A;
        }

        float getB()
        {
            return B;
        }

        float getC()
        {
            return C;
        }

        string getEventName()
        {
            return event_name;
        }

        EventType getEventType()
        {
            return event_type;
        }

};


class Simulation
{
    private:

        vector<Event> events;
        vector<Location> locations;
        vector<Team> teams;
        vector<int> meets;
        Athlete winner;
        map<int , string> mpMale;
        map<int , string> mpFemale;
        map<string , int> totalPerfMale; 
        map<string , int> totalPerfFemale;
        map<string , vector<int>> peak_factor ;
        map<Award , vector<string>> trophyMap;


    public:

        Simulation()
        {

        }

        void generatePlayerNamesMale()
        {
            mpMale.insert({0 , "John"});
            mpMale.insert({1 , "Jack"});
            mpMale.insert({2 , "Kevin"});
            mpMale.insert({3 , "Peter"});
            mpMale.insert({4 , "Paul"});
            mpMale.insert({5 , "Usain"});
            mpMale.insert({6 , "Mark"});
            mpMale.insert({7 , "Walter"});

        }

        void generatePlayerNamesFemale()
        {   
            mpFemale.insert({0 , "Cathy"});            
            mpFemale.insert({1 , "Julia"});
            mpFemale.insert({2 , "Paula"});
            mpFemale.insert({3 , "Joana"});
            mpFemale.insert({4 , "Taylor"});
            mpFemale.insert({5 , "Helen"});
            mpFemale.insert({6 , "Betty"});
            mpFemale.insert({7 , "Veronica"});

        }

        void generatePeakFactor(string nameAth)
        {
            for(int i =0 ; i<8 ; i++)
            {
                int x = randomGen(1,5);
                peak_factor[nameAth].push_back(x);
            }

        }

        void addTeam()
        {
            generatePlayerNamesMale();
            generatePlayerNamesFemale();

            for(int i =0 ; i<n ; i++)
            {
               
                Athlete m(mpMale[i] , 'M' , "Athlete");
                m.initAthlete();

                Athlete f(mpFemale[i] , 'F' , "Athlete");
                f.initAthlete();

                Physiotherapist p1;
                p1.setRecoverValue();

                Psychologist p2;
                p2.setHandleCapab();

                Trainer t1;
                t1.initTrainer(Track);
                t1.trainAthelete(m);

                Trainer t2;
                t2.initTrainer(Field);
                t2.trainAthelete(f);

                SupportCrew s;
                s.initSupportCrew(p1 , p2 , t1 , t2);    



                Team t;
                t.addAthlete(m , f);

                t.addSupportCrew(s);

                t.nameTeam("Team " + to_string(i+1));

                teams.push_back(t);

            }

        }



        void addEvents()
        {
            Event e1("100m race" , Track , 25.43,18, 1.18);
            Event e2("1500m race" , Track , 0.0376,480 ,1.85);
            Event e3("Hurdle race" , Track , 5.74, 28.5, 1.92);
            Event e4("40km race" , Track ,1 ,1, 1);
            Event e5("High Jump" , Field  ,1 ,1, 1);
            Event e6("Discus Throw" , Field , 12.91 ,4, 1.1);
            Event e7("Pole Vault" , Field , 0.2797 ,100, 1.35);
            Event e8("Shot Put" , Field , 51.39 ,1.5,1.05);

            events.push_back(e1);
            events.push_back(e2);
            events.push_back(e3);
            events.push_back(e4);
            events.push_back(e5);
            events.push_back(e6);
            events.push_back(e7);
            events.push_back(e8);
        }


        void addLocations()
        {
            Weather w1;
            Location l1("Greece" , w1 );

            Weather w2;
            Location l2("Australia" , w2);

            Weather w3;
            Location l3("Dubai" , w3);

            Weather w4;
            Location l4("London" , w4);

            Weather w5;
            Location l5("Tokyo" , w5);

            Weather w6;
            Location l6("Beijing" , w6);

            Weather w7;
            Location l7("Mars" , w7);

            Weather w8;
            Location l8("Moscow" , w8);

            Weather w9;
            Location l9("Paris" , w9);

            Weather w10;
            Location l10("Poland" , w10);


            locations.push_back(l1);
            locations.push_back(l2);
            locations.push_back(l3);
            locations.push_back(l4);
            locations.push_back(l5);
            locations.push_back(l6);
            locations.push_back(l7);
            locations.push_back(l8);
            locations.push_back(l9);
            locations.push_back(l10);

        }

        void setmeets()
        {
            int day = 1;
            int cnt = 0;

            while(cnt<2*m){

                if(meets.size() == 0)
                {   
                    meets.push_back(day);
                    day++;
                    cnt++;

                }

                else if(meets.size()%2 == 1)
                {
                    meets.push_back(day);  
                    int x = randomGen(5,7); 
                    day+=x;
                    cnt++;

                }

                else if(meets.size()%2 == 0)
                {

                    meets.push_back(day);
                    day++;
                    cnt++;

                }

            }

        }

        void getMaleWinner(int evtNum)
        {
            float x = INT_MIN;
            string temp;
            vector<pair<int, Athlete>> score;

            for(int i =0 ; i < teams.size() ; i++)
            {      
                float y = (teams[i].getMaleAth().getReadiness() + teams[i].getMaleAth().getStrength())*peak_factor[teams[i].getMaleAth().getName()][evtNum];
                totalPerfMale[teams[i].getMaleAth().getName()]+=y;

                score.push_back({y , teams[i].getMaleAth()});

            }

            sort(score.begin(), score.end() , cmp);
            cout<<"The Male winner for this event is : ";
            cout<<score[score.size()-1].second.getName();
            cout<<'\n';

           if(find(trophyMap[Gold].begin(), trophyMap[Gold].end() , score[score.size()-1].second.getName())  == trophyMap[Gold].end())
                trophyMap[Gold].push_back(score[score.size()-1].second.getName());

            if(find(trophyMap[Silver].begin(), trophyMap[Silver].end() , score[score.size()-2].second.getName())  == trophyMap[Silver].end())
                trophyMap[Silver].push_back(score[score.size()-2].second.getName());

            if(find(trophyMap[Bronze].begin(), trophyMap[Bronze].end() , score[score.size()-3].second.getName())  == trophyMap[Bronze].end())            
                trophyMap[Bronze].push_back(score[score.size()-3].second.getName());
            
        }

        void getFemaleWinner(int evtNum)
        {   
            float x = INT_MIN;
            string temp;
            vector<pair<int, Athlete>> score;

            for(int i =0 ; i < teams.size() ; i++)
            {            
                float y = (teams[i].getFemaleAth().getReadiness() + teams[i].getFemaleAth().getStrength())*peak_factor[teams[i].getFemaleAth().getName()][evtNum];
                totalPerfFemale[teams[i].getFemaleAth().getName()]+=y;

                score.push_back({y , teams[i].getFemaleAth()});                
            }

            sort(score.begin(), score.end() , cmp);
            cout<<"The Female winner for this event is : ";
            cout<<score[score.size()-1].second.getName();

            if(find(trophyMap[Gold].begin(), trophyMap[Gold].end() , score[score.size()-1].second.getName())  == trophyMap[Gold].end())
                trophyMap[Gold].push_back(score[score.size()-1].second.getName());

            if(find(trophyMap[Silver].begin(), trophyMap[Silver].end() , score[score.size()-2].second.getName())  == trophyMap[Silver].end())
                trophyMap[Silver].push_back(score[score.size()-2].second.getName());

            if(find(trophyMap[Bronze].begin(), trophyMap[Bronze].end() , score[score.size()-3].second.getName())  == trophyMap[Bronze].end())            
                trophyMap[Bronze].push_back(score[score.size()-3].second.getName());
            

        }

        void startSimulation()
        {
            this->setmeets();
            this->getMeets();
            this->addLocations();
            this->addEvents();
            this->addTeam();

            for(int i =0 ; i<8 ; i++)
            {
                this->generatePeakFactor(teams[i].getMaleAth().getName());
            }
            
            for(int i =0 ; i<8 ; i++)
            {
                this->generatePeakFactor(teams[i].getFemaleAth().getName());
            }
            

            for(int i =0 ;i<meets.size() ; i++)
            {
                cout<<"Welcome to Day :"<<meets[i]<<'\n';
                cout<<'\n';

                random_shuffle(locations.begin(), locations.end());

                cout<<"The location for this meet is:"<<locations[0].getLocation()<<'\n';
                cout<<"The weather here is - "<<locations[0].getWhtr().getWhtrName()<<'\n';
                cout<<'\n';

                random_shuffle(events.begin(), events.end());

                cout<<"First Event : "<<events[0].getEventName()<<'\n';
                getMaleWinner(0);
                getFemaleWinner(0);
                cout<<'\n'<<'\n';

                cout<<"Second Event : "<<events[1].getEventName()<<'\n';
                getMaleWinner(1);
                getFemaleWinner(1);
                cout<<'\n'<<'\n';

                cout<<"Third Event : "<<events[2].getEventName()<<'\n';
                getMaleWinner(2);
                getFemaleWinner(2);  
                cout<<'\n'<<'\n';

                cout<<"Fourth Event : "<<events[3].getEventName()<<'\n';
                getMaleWinner(3);
                getFemaleWinner(3);   
                cout<<'\n'<<'\n';

                cout<<'\n';
            }

            printStats();


           

        }

        void getMeets()
        {
            cout<<"Welcome to the Octathlon event.\nThe meets are set for following days : \n\n";

            for(auto i : meets)cout<<i<<" ";

            cout<<'\n';
            cout<<'\n';            

        }

       
        void printStats()
        {
            cout<<"----------------Season Stats----------------\n";
            cout<<'\n';

            cout<<"Female Contestants Score :\n";
            for(auto i : totalPerfFemale)cout<<i.first<<" "<<i.second<<'\n';

            cout<<'\n';

            cout<<"Male Contestants Score :\n";
            for(auto i : totalPerfMale)cout<<i.first<<" "<<i.second<<'\n';

            cout<<'\n';

            winnerMale();
            winnerFemale();


            cout<<"..........Award Stats..........\n";

            cout<<"Gold Winnners for sports events :\n";
            for(auto i : trophyMap[Gold])cout<<i<<'\n';
            cout<<'\n';

            cout<<"Silver Winnners for sports events :\n";
            for(auto i : trophyMap[Silver])cout<<i<<'\n';
            cout<<'\n';

            cout<<"Bronze Winnners for sports events :\n";
            for(auto i : trophyMap[Bronze])cout<<i<<'\n';
            cout<<'\n';

        }

        void winnerMale()
        {
            int x = INT_MIN ;
            string s;
            for(auto i : totalPerfMale)
            {
                if(i.second > x)
                {
                    x = i.second;
                    s = i.first;
                }
            }

            cout<<"The best Male contestant trophy for this season goes to : "<<s<<'\n';
            cout<<"Score : "<<x<<'\n';           
            cout<<'\n'; 

        }

        void winnerFemale()
        {
            int x = INT_MIN ;
            string s;
            for(auto i : totalPerfFemale)
            {
                if(i.second > x)
                {
                    x = i.second;
                    s = i.first;
                }
            }

            cout<<"The best Female contestant trophy for this season goes to : "<<s<<'\n';
            cout<<"Score : "<<x<<'\n';           
            cout<<'\n'; 

        }



};


int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    
   
    // n is the number of teams
    // m is the number of meets
    cin>>n>>m;

    Simulation Octathalon;
    Octathalon.startSimulation();

  

    
    return 0;
}

