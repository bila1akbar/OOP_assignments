#include <iostream>
#include <time.h>
using namespace std;
struct playerinfo
{
    int sr;
    string name;
    string type;
    float battingaverage;
    float battingstrikerate;
    float bowlingaverage;
    float bowlingstrikerate;
    int value;
    bool availability;
};
struct Team
{
    int teamrank[4];
    int teamnewplayers[4];
};
void playerdata(int &n, playerinfo *data, int &countbatsman, int &countbowler, int &countallrounder)
{

    int typee;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of " << i + 1 << " player ";
        cin >> data[i].name;
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "What type is " << data[i].name << " of \n1.Batsman \n2.Allrounder \n3.Bowler" << endl;
        cin >> typee;

        switch (typee)
        {
        case 1:

            data[i].type = "batsman";
            cout << "Enter the batting average of " << data[i].name << " player #" << (i + 1) << " : ";
            cin >> data[i].battingaverage;
            cout << "Enter the batting strikerate  of " << data[i].name << " : ";
            cin >> data[i].battingstrikerate;
            data[i].bowlingstrikerate = -1;
            data[i].bowlingaverage = -1;
            cout << "Enter the value of " << data[i].name << " : ";
            cin >> data[i].value;
            data[i].availability = 1;
            countbatsman++;
            cout << endl;
            cout << endl;
            break;
        case 3:

            data[i].type = "bowler";
            cout << "Enter the bowling average of " << data[i].name << " player #" << (i + 1) << " : ";
            cin >> data[i].bowlingaverage;
            cout << "Enter the bowling strikerate  of " << data[i].name << " : ";
            cin >> data[i].bowlingstrikerate;
            data[i].battingaverage = -1;
            data[i].battingstrikerate = -1;
            cout << "Enter the value of " << data[i].name << " : ";
            cin >> data[i].value;
            data[i].availability = 1;
            cout << endl;
            cout << endl;
            countbowler++;

            break;
        case 2:

            data[i].type = "Allrounder";
            cout << "Enter the batting average of " << data[i].name << " player #" << (i + 1) << " : ";
            cin >> data[i].battingaverage;
            cout << "Enter the batting strikerate  of " << data[i].name << " : ";
            cin >> data[i].battingstrikerate;
            cout << "Enter the bowling strikerate  of " << data[i].name << " : ";
            cin >> data[i].bowlingstrikerate;
            cout << "Enter the bowling average of " << data[i].name << " : ";
            cin >> data[i].bowlingaverage;
            cout << "Enter the value of " << data[i].name << " : ";
            cin >> data[i].value;
            data[i].availability = 1;
            cout << endl;
            cout << endl;
            countallrounder++;
            break;

        default:
            cout << "Not choosing from the menu" << endl;
            break;
        }
    }
}
void sortplayer(int &n, playerinfo *data, int &countbatsman, int &countbowler, int &countallrounder, int *batsmanarray, int *bowlerarray, int *allrounderarray)
{

    int term;
    string random;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            term = 0;
            if (data[i].battingaverage < data[j].battingaverage)
            {

                term = data[i].battingaverage;
                data[i].battingaverage = data[j].battingaverage;
                data[j].battingaverage = term;
                term = data[i].battingstrikerate;
                data[i].battingstrikerate = data[j].battingstrikerate;
                data[j].battingstrikerate = term;
                term = data[i].bowlingaverage;
                data[i].bowlingaverage = data[j].bowlingaverage;
                data[j].bowlingaverage = term;
                term = data[i].bowlingstrikerate;
                data[i].bowlingstrikerate = data[j].bowlingstrikerate;
                data[j].bowlingstrikerate = term;
                term = data[i].value;
                data[i].value = data[j].value;
                data[j].value = term;
                random = data[i].name;
                data[i].name = data[j].name;
                data[j].name = random;
                random = data[i].type;
                data[i].type = data[j].type;
                data[j].type = random;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (data[i].type == "Allrounder" && data[j].type == "batsman")
            {
                term = data[i].battingaverage;
                data[i].battingaverage = data[j].battingaverage;
                data[j].battingaverage = term;
                term = data[i].battingstrikerate;
                data[i].battingstrikerate = data[j].battingstrikerate;
                data[j].battingstrikerate = term;
                term = data[i].bowlingaverage;
                data[i].bowlingaverage = data[j].bowlingaverage;
                data[j].bowlingaverage = term;
                term = data[i].bowlingstrikerate;
                data[i].bowlingstrikerate = data[j].bowlingstrikerate;
                data[j].bowlingstrikerate = term;
                term = data[i].value;
                data[i].value = data[j].value;
                data[j].value = term;
                random = data[i].name;
                data[i].name = data[j].name;
                data[j].name = random;
                random = data[i].type;
                data[i].type = data[j].type;
                data[j].type = random;
            }
        }
    }

    int j = 0, k = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        data[i].sr = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (data[i].type == "batsman")
        {
            batsmanarray[j] = i;
            j++;
        }
        else if (data[i].type == "bowler")
        {

            bowlerarray[k] = i;
            k++;
        }
        else if (data[i].type == "Allrounder")
        {
            allrounderarray[l] = i;
            l++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
    }
}
void assignrank(Team &team)
{
    srand(time(NULL));
    team.teamrank[0] = 1 + (rand() % (4));
    team.teamrank[1] = 1 + (rand() % (4));
    while (team.teamrank[1] == team.teamrank[0])
        team.teamrank[1] = 1 + (rand() % (4));
    team.teamrank[2] = 1 + (rand() % (4));
    while (team.teamrank[2] == team.teamrank[0] || team.teamrank[2] == team.teamrank[1])
        team.teamrank[2] = 1 + (rand() % (4));
    team.teamrank[3] = 1 + (rand() % (4));
    while (team.teamrank[3] == team.teamrank[0] || team.teamrank[3] == team.teamrank[1] || team.teamrank[3] == team.teamrank[2])
        team.teamrank[3] = 1 + (rand() % (4));

    cout << "Ranking for teams are as follow : " << endl;
    for (int checking_rank = 1; checking_rank <= 4; checking_rank++)
    {
        if (checking_rank == team.teamrank[0])
        {
            cout << "The rank of team1 is :" << checking_rank << endl;
        }
        else if (checking_rank == team.teamrank[1])
        {
            cout << "The rank of team2 is :" << checking_rank << endl;
        }
        else if (checking_rank == team.teamrank[2])
        {
            cout << "The rank of team3 is :" << checking_rank << endl;
        }
        else if (checking_rank == team.teamrank[3])
        {
            cout << "The rank of team4 is :" << checking_rank << endl;
        }
    }
}

void teampicks(Team &team)
{
    int team1retain, team2retain, team3retain, team4retain;
    int checking_rank;
    for (checking_rank = 1; checking_rank <= 4; checking_rank++)
    {
        if (checking_rank == team.teamrank[3])
        {
            cout << " How many players team#4 want to retain (should not be less than 7 or greater than 11): ";
            cin >> team4retain;
            while (team4retain < 7 || team4retain > 11)
            {
                cout << "You dont meet the condition, Choose again : ";
                cin >> team4retain;
            }
        }
        else if (checking_rank == team.teamrank[0])
        {
            cout << " How many players team#1 want to retain (should not be less than 7 or greater than 11) : ";
            cin >> team1retain;
            while (team1retain < 7 || team1retain > 11)
            {
                cout << "You dont meet the condition, Choose again : ";
                cin >> team1retain;
            }
        }
        else if (checking_rank == team.teamrank[1])
        {

            cout << " How many players team#2 want to retain (should not be less than 7 or greater than 11): ";
            cin >> team3retain;
            while (team3retain < 7 || team3retain > 11)
            {
                cout << "You dont meet the condition, Choose again : ";
                cin >> team3retain;
            }
        }
        else if (checking_rank == team.teamrank[2])
        {
            cout << " How many players team#3 want to retain (should not be less than 7 or greater than 11): ";
            cin >> team2retain;
            while (team2retain < 7 || team2retain > 11)
            {
                cout << "You dont meet the condition, Choose again : ";
                cin >> team2retain;
            }
        }
    }
    team.teamnewplayers[0] = 16 - team1retain;
    team.teamnewplayers[1] = 16 - team2retain;
    team.teamnewplayers[2] = 16 - team3retain;
    team.teamnewplayers[3] = 16 - team4retain;

    cout << endl;
    cout << " The new players team#1 can have are " << team.teamnewplayers[0] << endl;
    cout << " The new players team#2 can have are " << team.teamnewplayers[1] << endl;
    cout << " The new players team#3 can have are " << team.teamnewplayers[2] << endl;
    cout << " The new players team#4 can have are " << team.teamnewplayers[3] << endl
         << endl;
}

void playerselection(Team &team, int *batsmanarray, int *bowlerarray, int *allrounderarray, int &countbatsman, int &countbowler, int &countallrounder, int &n, playerinfo *data)
{
    int catergory;
    int player;
    int i;
    for (int checking_rank = 1; checking_rank <= 4; checking_rank++)
    {
        if (checking_rank == team.teamrank[3])
        {
            for (int k = 0; k < team.teamnewplayers[3]; k++)
            {

                cout << "What type of player team#4  want \n1.Batsman \n2.Allrounder \n3.Bowler \n4.Skip" << endl;
                cin >> catergory;
                switch (catergory)
                {

                case 1:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type" << '\t' << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countbatsman; j++)
                    {
                        i = batsmanarray[j];

                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }
                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {

                        for (int j = 0; j < countbatsman; j++)
                        {
                            i = batsmanarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                    }

                    break;

                case 3:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type" << '\t' << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countbowler; j++)
                    {
                        i = bowlerarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {

                        for (int j = 0; j < countbowler; j++)
                        {
                            i = bowlerarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                    }

                    break;

                case 2:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type"
                         << "\t\t"
                         << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countallrounder; j++)
                    {
                        i = allrounderarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {

                        for (int j = 0; j < countallrounder; j++)
                        {
                            i = allrounderarray[j];
                            if (data[i].availability != 0)
                            {
                                if (data[i].sr == player)
                                {
                                    data[i].availability = 0;
                                }
                            }
                        }
                    }

                    break;
                case 4:
                    continue;
                }
            }
        }
        else if (checking_rank == team.teamrank[0])
        {
            for (int k = 0; k < team.teamnewplayers[0]; k++)
            {
                cout << team.teamnewplayers[0] << endl;
                cout << "What type of player team#1  want \n1.Batsman \n2.Allrounder \n3.Bowler \n4.Skip" << endl;
                cin >> catergory;
                switch (catergory)
                {

                case 1:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type" << '\t' << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countbatsman; j++)
                    {
                        i = batsmanarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {
                        for (int j = 0; j < countbatsman; j++)
                        {
                            i = batsmanarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                    }

                    break;

                case 3:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type" << '\t' << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countbowler; j++)
                    {
                        i = bowlerarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {

                        for (int j = 0; j < countbowler; j++)
                        {
                            i = bowlerarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                    }

                    break;

                case 2:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type"
                         << "\t\t"
                         << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countallrounder; j++)
                    {

                        i = allrounderarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {

                        for (int j = 0; j < countallrounder; j++)
                        {
                            i = allrounderarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                    }
                    break;
                case 4:
                    continue;
                }
            }
        }
        else if (checking_rank == team.teamrank[2])
        {
            for (int k = 0; k < team.teamnewplayers[2]; k++)
            {

                cout << "What type of player team#3  want \n1.Batsman \n2.Allrounder \n3.Bowler \n4.Skip" << endl;
                cin >> catergory;
                switch (catergory)
                {

                case 1:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type" << '\t' << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countbatsman; j++)
                    {

                        i = batsmanarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {
                        for (int j = 0; j < countbatsman; j++)
                        {
                            i = batsmanarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                    }

                    break;

                case 3:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type" << '\t' << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countbowler; j++)
                    {

                        i = bowlerarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {

                        for (int j = 0; j < countbowler; j++)
                        {
                            i = bowlerarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                    }

                    break;

                case 2:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type"
                         << "\t\t"
                         << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countallrounder; j++)
                    {

                        i = allrounderarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {

                        for (int j = 0; j < countallrounder; j++)
                        {
                            i = allrounderarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                        break;
                    case 4:
                        continue;
                    }
                }
            }
        }
        else if (checking_rank == team.teamrank[1])
        {
            for (int k = 0; k < team.teamnewplayers[1]; k++)
            {

                cout << "What type of player team#2  want \n1.Batsman \n2.Allrounder \n3.Bowler \n4.skip" << endl;
                cin >> catergory;
                switch (catergory)
                {

                case 1:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type" << '\t' << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;
                    for (int j = 0; j < countbatsman; j++)
                    {
                        i = batsmanarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {
                        for (int j = 0; j < countbatsman; j++)
                        {
                            i = batsmanarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                    }

                    break;

                case 3:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type" << '\t' << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countbowler; j++)
                    {

                        i = bowlerarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {

                        for (int j = 0; j < countbowler; j++)
                        {
                            i = bowlerarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }
                    }

                    break;

                case 2:

                    cout << "Sr #" << '\t' << "Name" << '\t' << "type"
                         << "\t\t"
                         << "Battingaverage" << '\t' << "Battingstrikerate" << '\t' << "Bowlingaverage" << '\t' << "Bowlingstrikerate" << '\t' << "Value" << '\t' << "Availability" << endl;

                    for (int j = 0; j < countallrounder; j++)
                    {
                        i = allrounderarray[j];
                        if (data[i].availability != 0)
                        {
                            cout << data[i].sr << '\t' << data[i].name << '\t' << data[i].type << '\t' << data[i].battingaverage << "\t\t" << data[i].battingstrikerate << "\t\t\t" << data[i].bowlingaverage << "\t\t" << data[i].bowlingstrikerate << "\t\t\t" << data[i].value << '\t' << data[i].availability << endl;
                        }
                    }

                    cout << "Pick a Player : (by typing the sr number) : ";
                    cin >> player;
                    if (player > 0)
                    {

                        for (int j = 0; j < countallrounder; j++)
                        {
                            i = allrounderarray[j];
                            if (data[i].availability != 0)
                            {

                                if (data[i].sr == player)
                                {

                                    data[i].availability = 0;
                                }
                            }
                        }

                        break;
                    case 4:
                        continue;
                    }
                }
            }
        }
    }
    delete[] data;
    delete[] batsmanarray;
    delete[] bowlerarray;
    delete[] allrounderarray;
}

int main()
{
    int n;
    cout << "How many players are there in Draft : ";
    cin >> n;
    cout << endl;
    playerinfo *data = new playerinfo[n];
    Team team;
    int countbatsman = 0, countallrounder = 0, countbowler = 0;
    playerdata(n, data, countbatsman, countbowler, countallrounder);
    int *batsmanarray = new int[countbatsman], *bowlerarray = new int[countbowler], *allrounderarray = new int[countallrounder];
    sortplayer(n, data, countbatsman, countbowler, countallrounder, batsmanarray, bowlerarray, allrounderarray);
    assignrank(team);
    teampicks(team);
    playerselection(team, batsmanarray, bowlerarray, allrounderarray, countbatsman, countbowler, countallrounder, n, data);

    return 0;
}
