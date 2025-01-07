//SMART RAILWAY MANAGEMENT SYSTEM

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <conio.h>
using namespace std;


// Structs

struct User

{
    string userID;
    string name;

    string phone;
    string email;

    string password;

};
struct Train
{
    string trainName;
    string trainNumber;

    string departurePlace;
    string arrivalPlace;

    string timings;
    string delayedTime;
    float price;

    string type;  // AC/Non-AC/Sleeper

    int seats;    // Number of seats available
};


struct Ticket

{
    string userID;

      // Associated user


    string name;


    int age;

    string trainName;

    string bookingType;

    // Online/Offline



    float price;

    string status;

      // Confirmed/Waiting


    string departure;
    string arrival;


    string timing;
    string date;


};

// Global Vectors


vector<User> users;

vector<Train> trains;


vector<Ticket> tickets;

// Function Prototypes
//void loadData();

void adminMenu();

void userMenu();


void addTrain();

void deleteTrain();


void updateDelayedTrain();

void registerUser();


void loginUser();

void viewRegisteredUsers();


void bookTicket(const string& userID);


void viewBookedTickets(const string& userID);


void cancelTicket(const string& userID);



void displayTrains();


void saveData();


void loadData();

// ANSI color codes


const string RED = "\033[31m";


const string GREEN = "\033[32m";

const string YELLOW = "\033[33m";


const string BLUE = "\033[34m";


const string CYAN = "\033[36m";


const string RESET = "\033[0m";


// Global Variable for Current User


string currentUserID;


// Main Function


int main()

{
    loadData();
    //loadData();

    int choice;


    while (true)

        {

        cout << CYAN << "\n================ Smart Railway Management System ==============\n" << RESET;


        cout << GREEN << "1. Admin\n2. User\n3. Exit\n" << RESET;


        cout << "Enter your choice: ";

        cin >> choice;



        if (cin.fail())


        {


            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');


            cout << RED << "Invalid input. Please enter a valid number.\n" << RESET;


            continue;
        }

        switch (choice)


         {
        case 1:
            adminMenu();


            break;
        case 2:


            userMenu();
            break;


        case 3:
            saveData();


            cout << GREEN << "Exiting... Thank you!\n" << RESET;
            return 0;


        default:


            cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }

    }
}



// Admin Menu
void adminMenu() {
    int choice;
    while (true) {
        cout << BLUE << "\n============ Admin Panel ===========\n" << RESET;

        cout << GREEN << "1. Add Train\n2. Delete Train\n3. Update Delayed Train\n4. View Registered Users\n5. Display Trains\n6. Back to Main Menu\n" << RESET;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)

         {
        case 1:
            addTrain();
            break;


        case 2:
            deleteTrain();
            break;


        case 3:
            updateDelayedTrain();
            break;


        case 4:
            viewRegisteredUsers();
            break;


        case 5:
            displayTrains();

             // Display trains in admin menu
            break;


        case 6:
            return;
        default:
            cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }
    }
}
// User Menu


void userMenu()


 {
    int choice;


    while (true)
    {
        cout << BLUE << "\n============ User Panel ==============\n" << RESET;

        cout << GREEN << "1. Register\n2. Login\n3. View Trains\n4. Back to Main Menu\n" << RESET;


        cout << "Enter your choice: ";


        cin >> choice;

        switch (choice)

         {
        case 1:
            registerUser();
            break;


        case 2:

            loginUser();
            break;


        case 3:
            displayTrains();
            break;



        case 4:
            return;


        default:
            cout << RED << "Invalid choice. Please try again.\n" << RESET;

        }


    }
}

// Add Train



void addTrain() {
    Train t;
    cout << "Enter Train Name: ";

    cin.ignore();
    getline(cin, t.trainName);

    cout << "Enter Train Number: ";

    cin >> t.trainNumber;

    cout << "Enter Departure Place: ";
    cin.ignore();
    getline(cin, t.departurePlace);

    cout << "Enter Arrival Place: ";

    getline(cin, t.arrivalPlace);

    cout << "Enter Departure_time-Arrival_time: ";
    getline(cin, t.timings);

    cout << "Enter Train Type (AC/Non-AC/Sleeper): ";

    cin >> t.type;

    cout << "Enter Base Ticket Price: ";

    cin >> t.price;

    cout << "Enter Delayed Time (if any, otherwise 'None'): ";


    cin.ignore();

    getline(cin, t.delayedTime);

    // Adding the new field for seats


    cout << "Enter the number of seats available: ";

    cin >> t.seats;

    trains.push_back(t);

    cout << GREEN << "Train added successfully!\n" << RESET;
}

// For _getch()






// Delete Train
void deleteTrain()

 {
    string trainNumber;

    cout << "Enter Train Number to Delete: ";

    cin >> trainNumber;


    for (auto it = trains.begin(); it != trains.end(); ++it)

        {
        if (it->trainNumber == trainNumber)


            {
            trains.erase(it);

            cout << GREEN << "Train deleted successfully!\n" << RESET;
            return;
        }

    }

    cout << RED << "Train not found.\n" << RESET;
}

// Update Delayed Train


void updateDelayedTrain()

 {
    string trainNumber, newTime;

    cout << "Enter Train Number to Update: ";

    cin >> trainNumber;




    for (auto& train : trains)

        {
        if (train.trainNumber == trainNumber)


        {
            cout << "Enter New Delayed Time: ";

            cin >> newTime;

            train.delayedTime = newTime;

            cout << GREEN << "Delayed time updated successfully!\n" << RESET;

            return;


        }

    }

    cout << RED << "Train not found.\n" << RESET;
}

// Register User
void registerUser()

{
    User u;
    cout << "Enter UserID: ";
    cin >> u.userID;

    cout << "Enter Name: ";
    cin.ignore();

    getline(cin, u.name);

    cout << "Enter Phone: ";
    cin >> u.phone;

    cout << "Enter Email: ";


    cin >> u.email;

    cout << "Enter Password (8 characters): ";

    char ch;
    u.password = "";

     // Initialize password as empty

    // Masking the password input with '*'
    while (true)

        {
        ch = _getch(); // Use _getch() to get a character without echoing it to the console

        if (ch == '\r')

            {
                // If Enter key is pressed, break the loop
            cout << endl;


            break;

        }

        else if (ch == '\b')

            {
                 // If Backspace key is pressed
            if (!u.password.empty())

            {
                u.password.pop_back();
        // Remove the last character from the password

                cout << "\b \b";

                  // Move the cursor back, print a space, and move back again
            }
        }
        else

            {
            u.password += ch;
        // Add character to the password

            cout << '*';

              // Display '' instead of the character
        }
    }

    // Validate the password length


    if (u.password.length() != 8)

        {

        cout << "\033[31mPassword must be exactly 8 characters long.\n\033[0m";
    // RED text

        return;
    }

    // Add the user to the users list

    users.push_back(u);


    cout << "\033[32mUser registered successfully!\n\033[0m"; // GREEN text
}

// Login User


void loginUser()

{
    string userID, password;

    cout << "Enter UserID: ";
    cin >> userID;

    cout << "Enter Password: ";

    char ch;
    password = ""; // Initialize password as empty

    // Masking the password input with '*'
    while (true)

        {
        ch = _getch(); // Use _getch() to get a character without echoing it to the console

        if (ch == '\r')

            { // If Enter key is pressed, break the loop
            cout << endl;
            break;


        } else if (ch == '\b')

        { // If Backspace key is pressed
            if (!password.empty())

                {
                password.pop_back(); // Remove the last character from the password
                cout << "\b \b";
            // Move the cursor back, print a space, and move back again

            }
        }
        else

            {
            password += ch; // Add character to the password
            cout << '*';    // Display '' instead of the character
        }
    }

    // Check if the entered userID and password match any user in the users list
    for (const auto& user : users)

        {
        if (user.userID == userID && user.password == password)

         {
            currentUserID = userID;
    // Set the current user

            cout << GREEN << "Login successful! Welcome, " << user.name << ".\n" << RESET;

            int choice;

            // User menu loop
            while (true)

                {
                cout << CYAN << "\n============== User Menu ==============\n" << RESET;
                cout << GREEN << "1. Book Ticket\n2. View Booked Tickets\n3. Cancel Ticket\n4. Logout\n" << RESET;
                cout << "Enter your choice: ";

                cin >> choice;

                // Handle user menu options
                switch (choice)

                 {
                    case 1:
                        bookTicket(userID);
                        break;

                    case 2:
                        viewBookedTickets(userID);
                        break;

                    case 3:
                        cancelTicket(userID);
                        break;

                    case 4:
                        cout << GREEN << "Logging out. Goodbye, " << user.name << ".\n" << RESET;
                        return; // Exit the function to log out

                    default:
                        cout << RED << "Invalid choice. Please try again.\n" << RESET;
                }
            }
        }
    }

    // If no match is found, display an error message


    cout << RED << "Invalid UserID or Password.\n" << RESET;
}


// Book Ticket


// Book Ticket

void bookTicket(const string& userID)


{
    if (trains.empty())
    {

        cout << RED << "No trains available for booking.\n" << RESET;


        return;
    }

    displayTrains();

    string trainNumber;

    cout << "Enter Train Number to book: ";


    cin >> trainNumber;

    for (const auto& train : trains)
    {

        if (train.trainNumber == trainNumber)
        {

            int numTickets;
            cout << "Enter the number of tickets to book: ";
            cin >> numTickets;

            for (int i = 0; i < numTickets; ++i)
            {
                Ticket t;
                t.userID = userID;

                cout << "Enter Passenger Name for ticket " << (i + 1) << ": ";
                cin.ignore();
                getline(cin, t.name);


                cout << "Enter Age for ticket " << (i + 1) << ": ";
                cin >> t.age;
                t.trainName = train.trainName;
                t.bookingType = "Online";

                t.price = train.price;
                t.status = "Confirmed";

                t.departure = train.departurePlace;
                t.arrival = train.arrivalPlace;
                t.timing = train.timings;

                cout << "Enter Travel Date (DD/MM/YYYY) for ticket " << (i + 1) << ": ";
                cin >> t.date;

                tickets.push_back(t);

                cout << GREEN << "Ticket " << (i + 1) << " booked successfully!\n" << RESET;
            }
            return;
        }
    }

    cout << RED << "Train not found.\n" << RESET;
}


// View Booked Tickets


void viewBookedTickets(const string& userID)

{
    bool found = false;


    cout << CYAN << "=========== Your Booked Tickets =========\n" << RESET;

    for (const auto& ticket : tickets)


        {
        if (ticket.userID == userID)

         {
            cout << YELLOW << "Passenger Name: " << ticket.name
                 << "\nAge: " << ticket.age


                 << "\nTrain Name: " << ticket.trainName
                 << "\nBooking Type: " << ticket.bookingType
                 << "\nPrice: " << ticket.price


                 << "\nStatus: " << ticket.status
                 << "\nDeparture: " << ticket.departure
                 << "\nArrival: " << ticket.arrival


                 << "\nTiming: " << ticket.timing
                 << "\nDate: " << ticket.date << "\n\n" << RESET;

            found = true;
        }
    }

    if (!found)

        {
        cout << RED << "No tickets booked yet.\n" << RESET;
    }
}

// Cancel Ticket
void cancelTicket(const string& userID)

{
    string passengerName;
    cout << "Enter the Passenger Name to cancel the ticket: ";
    cin.ignore();



    getline(cin, passengerName);


    for (auto it = tickets.begin(); it != tickets.end(); ++it)


        {
        if (it->userID == userID && it->name == passengerName)


        {
            tickets.erase(it);
            cout << GREEN << "Ticket cancelled successfully!\n" << RESET;
            return;
        }


    }



    cout << RED << "No ticket found for the given passenger name.\n" << RESET;
}

// Display Trains

void displayTrains() {
    if (trains.empty()) {
        cout << RED << "No trains available!\n" << RESET;
        return;
    }

    cout << YELLOW << left << setw(15) << "Train Name" << setw(15) << "Train Number"
         << setw(15) << "Departure" << setw(15) << "Arrival" << setw(10)
         << "Timings" << setw(10) << "Type" << setw(10) << "Price" << setw(15)
         << "Delayed Time" << setw(10) << "Seats\n"; // Added column for seats

    cout << "========================================================================================\n" << RESET;

    for (const auto& train : trains) {
        cout << left << setw(15) << train.trainName << setw(15) << train.trainNumber
             << setw(15) << train.departurePlace << setw(15) << train.arrivalPlace
             << setw(10) << train.timings << setw(10) << train.type
             << setw(10) << fixed << setprecision(2) << train.price
             << setw(15) << train.delayedTime << setw(10) << train.seats << "\n"; // Displaying seats
    }
}

// View Registered Users




void viewRegisteredUsers()


{
    if (users.empty()) {
        cout << RED << "No users registered.\n" << RESET;


        return;
    }

    cout << YELLOW << left << setw(15) << "UserID" << setw(20) << "Name" << setw(15) << "Phone" << setw(20) << "Email\n";


    cout << "====================================================================================================================================================================================================\n" << RESET;

    for (const auto& user : users)


        {
        cout << left << setw(15) << user.userID << setw(20) << user.name << setw(15) << user.phone << setw(20) << user.email << "\n";
    }
}

// Save Data

void saveData()
{
    // Save trains
    ofstream trainFile("trains.txt", ios::trunc);
    for (const auto& train : trains)
    {
        trainFile << train.trainName << "|" << train.trainNumber << "|"
                  << train.departurePlace << "|" << train.arrivalPlace << "|"
                  << train.timings << "|" << train.type << "|"
                  << train.price << "|" << train.delayedTime << "|"
                  << train.seats << "\n";
    }
    trainFile.close();

    // Save users
    ofstream userFile("users.txt", ios::trunc);
    for (const auto& user : users)
    {
        userFile << user.userID << "|" << user.name << "|" << user.phone << "|"
                 << user.email << "|" << user.password << "\n";
    }
    userFile.close();

    // Save tickets
    ofstream ticketFile("tickets.txt", ios::trunc);
    for (const auto& ticket : tickets)
    {
        ticketFile << ticket.userID << "|" << ticket.name << "|" << ticket.age << "|"
                   << ticket.trainName << "|" << ticket.bookingType << "|" << ticket.price << "|"
                   << ticket.status << "|" << ticket.departure << "|" << ticket.arrival << "|"
                   << ticket.timing << "|" << ticket.date << "\n";
    }
    ticketFile.close();
}

void loadData()
{
    // Clear existing data
    trains.clear();
    users.clear();
    tickets.clear();

    // Load trains
    ifstream trainFile("trains.txt");
    if (trainFile.is_open())
    {
        string line;
        while (getline(trainFile, line))
        {
            if (line.empty()) continue;
            Train train;
            stringstream ss(line);
            getline(ss, train.trainName, '|');
            getline(ss, train.trainNumber, '|');
            getline(ss, train.departurePlace, '|');
            getline(ss, train.arrivalPlace, '|');
            getline(ss, train.timings, '|');
            getline(ss, train.type, '|');
            ss >> train.price;
            ss.ignore(); // Ignore delimiter
            getline(ss, train.delayedTime, '|');
            ss >> train.seats;
            trains.push_back(train);
        }
        trainFile.close();
    }

    // Load users
    ifstream userFile("users.txt");
    if (userFile.is_open())
    {
        string line;
        while (getline(userFile, line))
        {
            if (line.empty()) continue;
            User user;
            stringstream ss(line);
            getline(ss, user.userID, '|');
            getline(ss, user.name, '|');
            getline(ss, user.phone, '|');
            getline(ss, user.email, '|');
            getline(ss, user.password, '|');
            users.push_back(user);
        }
        userFile.close();
    }

    // Load tickets
    ifstream ticketFile("tickets.txt");
    if (ticketFile.is_open())
    {
        string line;
        while (getline(ticketFile, line))
        {
            if (line.empty()) continue;
            Ticket ticket;
            stringstream ss(line);
            getline(ss, ticket.userID, '|');
            getline(ss, ticket.name, '|');
            ss >> ticket.age;
            ss.ignore(); // Ignore delimiter
            getline(ss, ticket.trainName, '|');
            getline(ss, ticket.bookingType, '|');
            ss >> ticket.price;
            ss.ignore(); // Ignore delimiter
            getline(ss, ticket.status, '|');
            getline(ss, ticket.departure, '|');
            getline(ss, ticket.arrival, '|');
            getline(ss, ticket.timing, '|');
            getline(ss, ticket.date, '|');
            tickets.push_back(ticket);
        }
        ticketFile.close();
    }
}

bool isTrainUnique(const string& trainNumber) {
    for (const auto& train : trains) {
        if (train.trainNumber == trainNumber) return false;
    }
    return true;
}



// Function to calculate the total fare for a train journey based on distance and fare per km

double calculateFare(double distance, double farePerKm)

 {

    return distance * farePerKm;

}

// Function to calculate the travel time based on distance and average speed


double calculateTravelTime(double distance, double averageSpeed)

{
    return distance / averageSpeed;
}

// Function to check if a train is delayed


bool isTrainDelayed(int scheduledArrivalTime, int actualArrivalTime)


 {

    return actualArrivalTime > scheduledArrivalTime;


}

// Function to check if a seat is available on a given train


bool isSeatAvailable(int totalSeats, int bookedSeats)

 {

    return bookedSeats < totalSeats;


}

// Function to calculate the total revenue from ticket sales for a train


double calculateRevenue(int totalTicketsSold, double ticketPrice)

{

    return totalTicketsSold * ticketPrice;

}

// Function to check if a train has enough fuel for the journey


bool hasEnoughFuel(double currentFuel, double requiredFuel)

 {

    return currentFuel >= requiredFuel;


}

// Function to check if a train is on time


bool isTrainOnTime(int scheduledDepartureTime, int actualDepartureTime)


{

    return actualDepartureTime <= scheduledDepartureTime;


}



// Function to calculate the total train capacity for a given number of compartments


int calculateTotalCapacity(int compartments, int seatsPerCompartment)


 {

    return compartments * seatsPerCompartment;

}

// Function to check if the train is overcrowded based on the total seats and passengers


bool isTrainOvercrowded(int totalSeats, int passengers)

{
    return passengers > totalSeats;

}

// Function to calculate the average speed of a train


double calculateAverageSpeed(double totalDistance, double totalTime)

{

    return totalDistance / totalTime;


}

// Function to determine the train class based on the class number (e.g., 1 for First Class, 2 for Second Class)


std::string trainClass(int classNumber)

 {


    if (classNumber == 1) return "First Class";


    else if (classNumber == 2) return "Second Class";


    else return "Sleeper Class";


}

// Function to check the train's maintenance schedule based on last maintenance date


bool isTrainDueForMaintenance(std::string lastMaintenanceDate, int monthsSinceLastMaintenance)


{


    return monthsSinceLastMaintenance > 6; // Example: the train requires maintenance after 6 months



}



// Function to calculate the estimated arrival time of a train given departure time and travel time


int calculateArrivalTime(int departureTime, double travelTime)


 {
    return departureTime + static_cast<int>(travelTime);


     // Assume travelTime is in hours
}

// Function to calculate the total train trip duration based on multiple legs (stops)


double calculateTotalJourneyTime(std::vector<double> journeyLegs)

{

    double totalTime = 0;


    for (double leg : journeyLegs)

     {

        totalTime += leg;


    }


    return totalTime;


}

// Function to calculate the occupancy rate of a train based on passengers and capacity


double calculateOccupancyRate(int passengers, int totalSeats)


{
    return (static_cast<double>(passengers) / totalSeats) * 100;



}

// Function to estimate fuel consumption for a train based on distance and fuel efficiency


double estimateFuelConsumption(double distance, double fuelEfficiency)

 {

    return distance / fuelEfficiency;
}

// Function to check the train's current status (e.g., "On Time", "Delayed", "Cancelled")


std::string getTrainStatus(bool isOnTime, bool isCancelled)


 {


    if (isCancelled) return "Cancelled";


    return isOnTime ? "On Time" : "Delayed";


}

// Function to simulate booking a ticket, assuming available seats


bool bookTicket(int& availableSeats)

{


    if (availableSeats > 0)

        {


        availableSeats--;


        return true;


    }


    return false;


}

// Function to check the train type (e.g., "Express", "Local", "Cargo")



std::string trainType(int trainCode)


{
    if (trainCode == 1) return "Express";



    else if (trainCode == 2) return "Local";



    else return "Cargo";
}
std::string trainNType(int trainCode)


{


    if (trainCode == 1) return "Express";


    else if (trainCode == 2) return "Local";


    else return "Cargo";
}

bool activateEmergencyBrakes(double speed, double responseTime);

std::string reportSafetyViolation(int violationCode);


bool isSafetyProtocolFollowed(int safetyScore);

std::string generateEmergencyResponsePlan(int trainId);


bool validateEvacuationPlan(std::string planId);

int estimateEmergencyResponseTime(int locationId);


bool isFireSafetyEquipmentOperational(int trainId);


std::string reportAccidentDetails(int trainId, std::string date);


bool testAutomaticControlSystem(int trainId);


int calculateEmergencyStopDistance(double speed, double reactionTime);

// Function to calculate the train's average speed
double computeAverageTrainSpeed(double distanceCovered, double timeTaken)
{
    return distanceCovered / timeTaken;
}

// Function to estimate travel distance using start and end points
double estimateTravelDistance(double startPoint, double endPoint)
{
    return endPoint - startPoint;
}

// Function to find the maximum speed of the train
double findMaxTrainSpeed(std::vector<double> speedRecords)
{
    double maxSpeed = 0.0;
    for (double speed : speedRecords)
    {
        if (speed > maxSpeed)
        {
            maxSpeed = speed;
        }
    }
    return maxSpeed;
}

// Function to check if train meets minimum speed requirements
bool isSpeedAboveMinimum(double currentSpeed, double minSpeed)
{
    return currentSpeed >= minSpeed;
}

// Function to calculate time required to travel a specific distance
double calculateTimeForDistance(double distance, double speed)
{
    return distance / speed;
}



// Function to announce the current station
std::string announceCurrentStation(std::string stationName)
{
    return "Now arriving at " + stationName;
}

// Function to check if a station exists in the route
bool isStationOnRoute(std::vector<std::string> route, std::string stationName)
{
    for (const std::string& station : route)
    {
        if (station == stationName)
        {
            return true;
        }
    }
    return false;
}

// Function to calculate layover time at a station
int calculateLayoverTime(int arrivalTime, int departureTime)
{
    return departureTime - arrivalTime;
}

// Function to get the next station on the route
std::string getNextStation(std::vector<std::string> route, std::string currentStation)
{
    for (size_t i = 0; i < route.size(); ++i)
    {
        if (route[i] == currentStation && i + 1 < route.size())
        {
            return route[i + 1];
        }
    }
    return "End of route";
}

// Function to validate the train schedule
bool validateTrainSchedule(std::vector<int> timings)
{
    for (size_t i = 1; i < timings.size(); ++i)
    {
        if (timings[i] <= timings[i - 1])
        {
            return false; // Schedule is invalid
        }
    }
    return true;
}

// Function to calculate ticket price based on class and distance
double computeTicketPrice(int classCode, double distance)
{
    double baseFare = classCode == 1 ? 2.0 : 1.5; // Higher fare for First Class
    return distance * baseFare;
}

// Function to issue a ticket
bool issuePassengerTicket(int& seatsAvailable, int passengerId)
{
    if (seatsAvailable > 0)
    {
        --seatsAvailable;
        return true; // Ticket successfully issued
    }
    return false; // No seats available
}

// Function to check if ticket booking is allowed
bool isBookingAllowed(int availableSeats, int maxCapacity)
{
    return availableSeats <= maxCapacity;
}

// Function to cancel a ticket and refund a seat
bool cancelPassengerTicket(int& bookedSeats)
{
    ++bookedSeats;
    return true; // Cancellation successful
}

// Function to calculate total revenue generated from tickets
double calculateTotalRevenue(std::vector<int> ticketsSold, double farePerTicket)


{
    double totalRevenue = 0.0;
    for (int tickets : ticketsSold)
    {
        totalRevenue += tickets * farePerTicket;
    }
    return totalRevenue;
}


// Function to check if a train passes through a specific station
bool doesTrainPassThroughStation(std::vector<std::string> route, std::string stationName)
{
    for (const std::string& station : route)
    {
        if (station == stationName)
        {
            return true;
        }
    }
    return false;
}

// Function to find the index of a station in the route
int getStationIndex(std::vector<std::string> route, std::string stationName)
{
    for (size_t i = 0; i < route.size(); ++i)
    {
        if (route[i] == stationName)
        {
            return i;
        }
    }
    return -1; // Station not found
}

// Function to calculate the distance between two stations
double calculateDistanceBetweenStations(std::vector<double> distances, int startIndex, int endIndex)
{
    double totalDistance = 0.0;

    for (int i = startIndex; i < endIndex; ++i)
    {
        totalDistance += distances[i];
    }

    return totalDistance;
}

// Function to validate the train route
bool validateTrainRoute(std::vector<std::string> route)
{
    return !route.empty(); // A valid route must have at least one station
}

// Function to count the total number of stations in a route
int countStationsInRoute(std::vector<std::string> route)
{
    return route.size();
}

// Function to add a new station to the route
bool addStationToRoute(std::vector<std::string>& route, std::string stationName)
{
    route.push_back(stationName);
    return true;
}



// Function to get the total distance of the route
double getTotalRouteDistance(std::vector<double> distances)
{
    double totalDistance = 0.0;

    for (double distance : distances)
    {
        totalDistance += distance;
    }

    return totalDistance;
}

// Function to check if a station is a terminal station
bool isTerminalStation(std::vector<std::string> route, std::string stationName)
{
    return (stationName == route.front() || stationName == route.back());
}


// Function to check if emergency brakes are operational
bool checkEmergencyBrakesStatus(int trainId)
{
    // Placeholder for actual check
    return true;
}

// Function to activate emergency protocols
std::string activateEmergencyProtocol(int trainId)
{
    return "Emergency protocol activated for Train ID: " + std::to_string(trainId);
}

// Function to generate a safety compliance report
std::string generateSafetyComplianceReport(int trainId)


{

    return "Train ID " + std::to_string(trainId) + " is compliant with safety standards.";
}

// Function to check fire safety equipment
bool checkFireSafetyEquipment(int trainId)
{

    // Placeholder for fire safety check
    return true;

}

// Function to validate evacuation plan
bool validateEvacuationPlan(std::string planId)
{


    // Example: Placeholder validation
    return true;

}

// Function to simulate a safety drill


bool simulateSafetyDrill(int trainId)
{
    // Example: Always successful


    return true;
}

// Function to calculate the time to stop in an emergency


double calculateEmergencyStopTime(double speed, double decelerationRate)
{
    return speed / decelerationRate;


}

// Function to log a safety incident
bool logSafetyIncident(int trainId, std::string incidentDetails)


{
    // Example: Log the incident (placeholder)


    return true;
}

// Function to calculate emergency evacuation time

double calculateEvacuationTime(int passengers, double evacuationRate)


{
    return passengers / evacuationRate;


}

// Function to test train horn functionality
bool testTrainHorn(int trainId)


{

    // Placeholder for horn test

    return true;
}


// Function to check if dining services are available


bool checkDiningServiceAvailability(int trainId)

{

    // Placeholder check
    return true;

}

// Function to list available meals in the dining car

std::vector<std::string> getDiningMenu(int trainId)

{
    return {"Sandwich", "Coffee", "Pasta", "Salad"};

}

// Function to check if WiFi is available on the train

bool isWiFiAvailable(int trainId)
{

    // Placeholder check

    return true;
}

// Function to list available entertainment options

std::vector<std::string> getEntertainmentOptions(int trainId)


{

    return {"Movies", "Music", "Games", "Books"};
}

// Function to check if onboard staff is available

bool isStaffAvailable(int trainId)



{
    // Placeholder check
    return true;
}

// Function to estimate the luggage capacity in a coach


double calculateLuggageCapacity(int coachId, double capacityPerPassenger)


{
    int passengers = 50; // Example: Fixed number of passengers




    return passengers * capacityPerPassenger;


}

// Function to fetch a list of passenger complaints


std::vector<std::string> fetchPassengerComplaints(int trainId)
{


    return {"AC not working", "Delay in service", "WiFi issues"};


}

// Function to log a new passenger complaint



bool logPassengerComplaint(int trainId, std::string complaintDetails)

{


    // Example: Log the complaint (placeholder)
    return true;


}

// Function to calculate passenger satisfaction score


double calculatePassengerSatisfactionScore(int totalFeedbacks, int positiveFeedbacks)


{

    return (static_cast<double>(positiveFeedbacks) / totalFeedbacks) * 100.0;


}

// Function to assign seating arrangements for a group


std::vector<int> assignGroupSeating(int groupSize, int startSeat)


{
    std::vector<int> seats;

    for (int i = 0; i < groupSize; ++i)


    {
        seats.push_back(startSeat + i);


    }


    return seats;

}

// Function to check if a train is on schedule
bool isTrainOnSchedule(int scheduledTime, int actualTime)
{
    return actualTime <= scheduledTime;
}

// Function to calculate delay time for a train
int calculateTrainDelay(int scheduledArrival, int actualArrival)
{
    return actualArrival - scheduledArrival;
}

// Function to update the train schedule
bool updateTrainSchedule(int trainId, int newDepartureTime, int newArrivalTime)
{
    // Example: Update the schedule in the database (placeholder)
    return true;
}

// Function to fetch the next train's schedule
std::string fetchNextTrainSchedule(std::string stationName)
{
    // Placeholder for fetching schedule
    return "Train 101 at 10:30 AM";
}

// Function to calculate turnaround time at a station
int calculateTurnaroundTime(int arrivalTime, int nextDepartureTime)
{

    return nextDepartureTime - arrivalTime;
}

// Function to list trains arriving at a specific station
std::vector<std::string> listTrainsAtStation(std::string stationName)
{
    return {"Train 101", "Train 202", "Train 303"};
}

// Function to count the number of trains scheduled for the day
int countDailyTrains(std::vector<std::string> schedule)
{

    return schedule.size();
}

// Function to generate a timetable for a specific route

std::string generateTimetable(std::vector<std::string> stations, std::vector<int> timings)
{

    std::string timetable = "Station - Timing\n";


    for (size_t i = 0; i < stations.size(); ++i)

    {

        timetable += stations[i] + " - " + std::to_string(timings[i]) + "\n";

    }

    return timetable;
}

// Function to check if a train is running overnight
bool isOvernightTrain(int departureTime, int arrivalTime)
{

    return arrivalTime < departureTime;

}

// Function to fetch all trains running between two stations

std::vector<std::string> fetchTrainsBetweenStations(std::string startStation, std::string endStation)

{
    return {"Express 101", "Local 202", "Sleeper 303"};

}
// Function to calculate fuel consumption for a journey

double calculateFuelUsage(double distance, double fuelEfficiency)


{

    return distance / fuelEfficiency;
}

// Function to estimate fuel cost for a journey

double estimateFuelCost(double fuelUsage, double fuelPricePerLiter)
{
    return fuelUsage * fuelPricePerLiter;
}

// Function to track the fuel level in the train
double trackFuelLevel(double currentFuel, double consumption)
{


    return currentFuel - consumption;


}

// Function to calculate the distance the train can travel with remaining fuel


double calculateRemainingDistance(double fuelLevel, double fuelEfficiency)
{


    return fuelLevel * fuelEfficiency;

}

// Function to determine if a train needs refueling


bool needsRefueling(double currentFuel, double minimumFuelRequired)
{
    return currentFuel < minimumFuelRequired;
}

// Function to log fuel consumption for a train journey
bool logFuelConsumption(int trainId, double fuelUsed)

{
    // Example: Log to a database (placeholder)

    return true;
}

// Function to calculate average fuel efficiency for a train

double calculateAverageFuelEfficiency(std::vector<double> efficiencyReadings)

{
    double totalEfficiency = 0.0;

    for (double reading : efficiencyReadings)


    {
        totalEfficiency += reading;
    }

    return totalEfficiency / efficiencyReadings.size();

}

// Function to monitor real-time fuel efficiency

double monitorRealTimeEfficiency(double speed, double fuelRate)

{
    return speed / fuelRate;

}

// Function to fetch the last fuel refill date


std::string getLastRefillDate(int trainId)


{
    return "2024-12-01";

    // Placeholder

}

// Function to schedule a fuel refill

bool scheduleFuelRefill(int trainId, std::string refillDate)
{


    // Example: Schedule the refill in the system (placeholder)

    return true;

}


// Function to display train status on a board
std::string displayTrainStatus(std::string trainName, std::string status)
{
    return "Train: " + trainName + " | Status: " + status;
}

// Function to provide boarding announcements
std::string generateBoardingAnnouncement(std::string trainName, std::string platform)
{
    return "Train " + trainName + " is now boarding at platform " + platform;
}

// Function to list amenities available on the train
std::vector<std::string> listTrainAmenities(int trainId)
{
    return {"WiFi", "Dining", "Reclining Seats", "Entertainment"};
}

// Function to update train status on the display
bool updateTrainStatusOnBoard(int trainId, std::string newStatus)
{
    // Placeholder: Assume status is updated
    return true;
}

// Function to alert passengers about delays
std::string alertPassengersAboutDelay(int delayMinutes)
{
    return "The train is delayed by " + std::to_string(delayMinutes) + " minutes.";
}

// Function to display next available train
std::string displayNextAvailableTrain(std::string stationName)
{
    return "Next available train: Express 101 at 12:00 PM";
}

// Function to show a list of passenger names
std::vector<std::string> listPassengerNames(std::vector<int> passengerIds)
{
    // Placeholder: Map IDs to names
    return {"John Doe", "Jane Smith", "Alex Johnson"};
}

// Function to fetch travel history for a passenger
std::vector<std::string> fetchPassengerTravelHistory(int passengerId)
{
    return {"Train 101: Station A to Station B", "Train 202: Station C to Station D"};
}

// Function to provide real-time train location updates
std::string getRealTimeLocation(int trainId)
{
    return "Currently at Station X"; // Placeholder
}

// Function to send automated reminders for upcoming trains
bool sendTrainReminder(int passengerId, std::string trainDetails)
{
    // Placeholder: Assume reminder is sent
    return true;
}
// Function to calculate average passenger load
double calculateAverageLoad(std::vector<int> dailyLoads)
{
    double totalLoad = 0.0;

    for (int load : dailyLoads)
    {
        totalLoad += load;
    }

    return totalLoad / dailyLoads.size();
}

// Function to determine peak travel times
std::string findPeakTravelTimes(std::vector<int> hourlyPassengerCounts)
{
    int peakHour = 0;
    int maxCount = 0;

    for (size_t i = 0; i < hourlyPassengerCounts.size(); ++i)
    {
        if (hourlyPassengerCounts[i] > maxCount)
        {
            maxCount = hourlyPassengerCounts[i];
            peakHour = i;
        }
    }

    return "Peak hour: " + std::to_string(peakHour) + ":00 with " + std::to_string(maxCount) + " passengers.";
}

// Function to calculate revenue from ticket sales
double calculateTicketRevenue(std::vector<int> ticketsSold, std::vector<double> ticketPrices)
{
    double totalRevenue = 0.0;

    for (size_t i = 0; i < ticketsSold.size(); ++i)
    {
        totalRevenue += ticketsSold[i] * ticketPrices[i];
    }

    return totalRevenue;
}

// Function to fetch passenger demographics
std::vector<std::string> getPassengerDemographics(int trainId)
{
    return {"Adults: 70%", "Children: 20%", "Seniors: 10%"};
}

// Function to calculate passenger retention rate
double calculateRetentionRate(int returningPassengers, int totalPassengers)
{
    return (static_cast<double>(returningPassengers) / totalPassengers) * 100.0;
}

// Function to analyze passenger feedback
std::string analyzeFeedback(std::vector<std::string> feedbacks)
{
    int positive = 0, negative = 0;

    for (const std::string& feedback : feedbacks)
    {
        if (feedback.find("good") != std::string::npos || feedback.find("excellent") != std::string::npos)
        {
            ++positive;
        }
        else
        {
            ++negative;
        }
    }

    return "Positive feedback: " + std::to_string(positive) + ", Negative feedback: " + std::to_string(negative);
}

// Function to predict future passenger trends
std::vector<int> predictPassengerTrends(std::vector<int> pastTrends, int years)
{
    std::vector<int> predictions = pastTrends;

    for (int i = 0; i < years; ++i)
    {
        predictions.push_back(predictions.back() * 1.05); // Example: 5% growth
    }

    return predictions;
}

// Function to determine average ticket price
double calculateAverageTicketPrice(std::vector<double> ticketPrices)
{
    double total = 0.0;

    for (double price : ticketPrices)
    {
        total += price;
    }

    return total / ticketPrices.size();
}

// Function to log passenger behavior insights
bool logPassengerInsights(std::string insightDetails)
{
    // Placeholder: Assume insights are logged
    return true;
}

// Function to analyze seat occupancy patterns
std::string analyzeOccupancyPatterns(std::vector<int> seatOccupancies)
{
    double averageOccupancy = calculateAverageLoad(seatOccupancies);
    return "Average seat occupancy: " + std::to_string(averageOccupancy) + "%.";
}
// Function to monitor train speed in real-time
double monitorTrainSpeed(int trainId)
{
    // Placeholder: Assume a constant speed
    return 80.0; // km/h
}

// Function to check if automation systems are active
bool areAutomationSystemsActive(int trainId)
{
    // Placeholder: Assume systems are active
    return true;
}

// Function to calculate energy consumption
double calculateEnergyConsumption(double speed, double time, double efficiencyFactor)
{
    return (speed * time) / efficiencyFactor;
}

// Function to simulate train operation
bool simulateTrainOperation(int trainId, double duration)
{
    // Placeholder: Assume successful simulation
    return true;
}

// Function to update automation system software
bool updateAutomationSoftware(int trainId, std::string version)
{
    // Placeholder: Assume update is successful
    return true;
}

// Function to log system alerts
bool logSystemAlert(int trainId, std::string alertMessage)

{
    // Placeholder: Assume alert is logged

    return true;
}

// Function to fetch current train diagnostics

std::string fetchTrainDiagnostics(int trainId)
{


    return "Speed: 80 km/h, Fuel: 70%, Temperature: Normal";
    // Placeholder

}

// Function to generate an automation system report


std::string generateAutomationReport(int trainId)


{
    return "Automation systems are functioning as expected.";

    // Placeholder
}

// Function to monitor electrical systems


bool monitorElectricalSystems(int trainId)
{

    // Placeholder: Assume systems are operational

    return true;
}

// Function to schedule automation testing

bool scheduleAutomationTest(int trainId, std::string testDate)
{
    // Placeholder: Assume test is scheduled

    return true;
}
// Function to check if emergency brakes are functioning

bool areEmergencyBrakesFunctional(int trainId)


{
    // Placeholder: Assume brakes are functional
    return true;
}

// Function to simulate emergency evacuation

bool simulateEmergencyEvacuation(int trainId)

{
    // Placeholder: Assume simulation is successful

    return true;
}

// Function to track fire safety equipment status


bool isFireSafetyEquipmentOperational(int trainId)

{
    // Placeholder: Assume equipment is operational


    return true;
}

// Function to log safety incidents

// Function to calculate average time for emergency response

double calculateEmergencyResponseTime(std::vector<int> responseTimes)
{
    int total = 0;


    for (int time : responseTimes)

    {
        total += time;
    }

    return static_cast<double>(total) / responseTimes.size();


}

// Function to check the train's derailment detection system
bool isDerailmentDetectionSystemActive(int trainId)
{
    // Placeholder: Assume system is active

    return true;
}

// Function to update safety protocols


bool updateSafetyProtocols(int trainId, std::string protocolDetails)


{
    // Placeholder: Assume update is successful


    return true;
}

// Function to verify seatbelt functionality

bool verifySeatbeltStatus(int seatId)
{
    // Placeholder: Assume seatbelt is functional
    return true;
}

// Function to simulate onboard safety drill


// Function to calculate safety compliance score


double calculateSafetyComplianceScore(int trainId, int checksPassed, int totalChecks)


{

    return (static_cast<double>(checksPassed) / totalChecks) * 100.0;

}
// Function to fetch real-time weather for the train's route

std::string fetchWeatherForRoute(std::string startLocation, std::string endLocation)

{
    return "Sunny, 25°C";

    // Placeholder
}

// Function to calculate weather impact on train speed


double calculateWeatherImpact(double speed, std::string weatherCondition)


{


    if (weatherCondition == "Rainy") return speed * 0.8;

    // Example: 20% reduction

    if (weatherCondition == "Snowy") return speed * 0.6;

    // Example: 40% reduction


    return speed;

    // No impact
}

// Function to issue weather advisories to passengers


std::string issueWeatherAdvisory(std::string weatherCondition)


{
    if (weatherCondition == "Rainy") return "Carry an umbrella. Expect minor delays.";

    if (weatherCondition == "Snowy") return "Dress warmly. Delays possible.";


    return "Weather is clear. Safe travels!";


}

// Function to reschedule trains due to extreme weather

bool rescheduleTrainsForWeather(std::vector<int> trainIds, std::string weatherCondition)


{
    // Placeholder: Assume rescheduling is successful

    return true;
}

// Function to log weather delays


bool logWeatherDelay(int trainId, std::string weatherCondition, int delayMinutes)
{

    // Placeholder: Assume delay is logged


    return true;
}

// Function to calculate average delay due to weather

double calculateAverageWeatherDelay(std::vector<int> delayMinutes)
{
    int total = 0;

    for (int delay : delayMinutes)

    {

        total += delay;


    }

    return static_cast<double>(total) / delayMinutes.size();
}

// Function to fetch real-time temperature for the train's location

double fetchRealTimeTemperature(std::string location)


{
    return 24.5; // Placeholder temperature in Celsius
}


// Function to determine if the train should halt due to weather

bool shouldTrainHaltForWeather(std::string weatherCondition)

{


    return weatherCondition == "Stormy" || weatherCondition == "Blizzard";
}

// Function to suggest alternate routes based on weather

std::vector<std::string> suggestAlternateRoutes(std::string originalRoute, std::string weatherCondition)
{
    if (weatherCondition == "Flooded")


    {
        return {"Route A: Safe detour", "Route B: Extended but clear"};


    }
    return {originalRoute};


}

// Function to alert passengers of severe weather disruptions

std::string alertSevereWeather(std::string weatherCondition)


{
    return "Severe " + weatherCondition + " expected. Check for updates.";


}
// Function to calculate average trip duration for all trains

double calculateAverageTripDuration(std::vector<double> tripDurations)

{
    double total = 0.0;

    for (double duration : tripDurations)


    {
        total += duration;


    }

    return total / tripDurations.size();

}

// Function to predict next year's passenger growth


double predictPassengerGrowth(double currentPassengers, double growthRate)


{
    return currentPassengers * (1 + growthRate / 100.0);


}

// Function to rank trains by occupancy rate


std::vector<int> rankTrainsByOccupancy(std::vector<int> trainIds, std::vector<double> occupancyRates)
{
    // Placeholder: Sort trains by occupancy rates

    return trainIds;
}

// Function to analyze train punctuality

double analyzePunctuality(std::vector<int> delays)
{
    int onTimeCount = 0;

    for (int delay : delays)
    {


        if (delay <= 0) ++onTimeCount;
    }



    return (static_cast<double>(onTimeCount) / delays.size()) * 100.0;
}

// Function to identify most profitable routes


std::string identifyProfitableRoutes(std::vector<std::string> routes, std::vector<double> revenues)
{
    double maxRevenue = 0.0;


    std::string bestRoute;


    for (size_t i = 0; i < routes.size(); ++i)
    {

        if (revenues[i] > maxRevenue)


        {
            maxRevenue = revenues[i];


            bestRoute = routes[i];
        }
    }

    return bestRoute;

}

// Function to calculate average revenue per train


double calculateAverageRevenuePerTrain(std::vector<double> revenues)
{
    double total = 0.0;

    for (double revenue : revenues)


    {
        total += revenue;
    }



    return total / revenues.size();
}

// Function to detect underperforming routes


std::vector<std::string> detectUnderperformingRoutes(std::vector<std::string> routes, std::vector<double> revenues, double threshold)
{

    std::vector<std::string> underperformingRoutes;



    for (size_t i = 0; i < routes.size(); ++i)


    {
        if (revenues[i] < threshold)
        {


            underperformingRoutes.push_back(routes[i]);


        }
    }

    return underperformingRoutes;
}

// Function to log analytics insights


bool logAnalyticsInsight(std::string insightDetails)
{
    // Placeholder: Assume insights are logged


    return true;
}

// Function to calculate train utilization efficiency


double calculateTrainUtilization(double occupancyRate, double fuelEfficiency)


{
    return occupancyRate * fuelEfficiency / 100.0;

}

// Function to forecast next quarter's revenue


double forecastQuarterlyRevenue(double currentRevenue, double growthRate)




{
    return currentRevenue * (1 + growthRate / 100.0);


}
// Function to calculate the shortest route between two stations



std::string calculateShortestRoute(std::string startStation, std::string endStation, std::vector<std::string> routes)


{
    // Placeholder: Assume route "Route A" is the shortest


    return "Route A";
}

// Function to calculate fuel required for a specific route
double calculateFuelForRoute(double distance, double fuelEfficiency)


{
    return distance / fuelEfficiency;

}

// Function to check train route feasibility


bool isRouteFeasible(std::string routeName, std::string weatherCondition)
{
    // Placeholder: Assume route is feasible


    return weatherCondition != "Flooded";
}

// Function to optimize train schedules based on demand


std::string optimizeTrainSchedule(std::vector<int> trainIds, std::vector<int> passengerCounts)


{
    return "Schedule optimized based on passenger density.";
}

// Function to add a new stop to an existing route


bool addStopToRoute(std::string routeName, std::string newStop)
{
    // Placeholder: Assume stop is added


    return true;
}

// Function to log route performance metrics








bool logRoutePerformance(std::string routeName, double occupancyRate, double revenue)


{
    // Placeholder: Assume performance is logged


    return true;
}

// Function to determine route profitability

bool isRouteProfitable(double revenue, double operationalCost)


{
    return revenue > operationalCost;

}

// Function to track real-time location of trains on a route
std::vector<std::string> getRealTimeTrainLocations(std::string routeName)


{
    return {"Train A: Station 3", "Train B: Between Station 5 and 6"};

    // Placeholder
}

// Function to assign priority to high-demand routes


std::string assignRoutePriority(std::string routeName, int passengerCount)


{
    return passengerCount > 1000 ? "High Priority" : "Low Priority";
}

// Function to analyze route congestion


double analyzeRouteCongestion(std::string routeName, int trainCount)
{
    return static_cast<double>(trainCount) * 0.8;

    // Example: Congestion factor
}
// Function to predict train delay based on weather and route conditions


int predictDelay(std::string weatherCondition, double distance, int averageSpeed)


{
    if (weatherCondition == "Rainy") return static_cast<int>(distance / averageSpeed) + 15;

     // 15 min delay


    return static_cast<int>(distance / averageSpeed);
}

// Function to recommend optimal departure times for trains


std::string recommendDepartureTime(std::vector<int> demandData)


{
    return "6:00 AM";

     // Placeholder: Optimal based on demand
}

// Function to analyze passenger booking patterns


std::vector<int> analyzeBookingPatterns(std::vector<int> dailyBookings)


{
    // Placeholder: Return adjusted predictions


    return dailyBookings;
}

// Function to generate personalized offers for passengers
std::string generatePersonalizedOffer(int passengerId, std::string travelHistory)


{
    return "10% off on your next booking!"; // Placeholder
}

// Function to calculate real-time demand predictions
double predictRealTimeDemand(int currentBookings, double growthRate)
{

    return currentBookings * (1 + growthRate / 100.0);


}

// Function to monitor AI system health


bool monitorAISystemHealth()
{
    // Placeholder: Assume system is healthy


    return true;
}

// Function to analyze seasonal passenger trends


std::vector<int> analyzeSeasonalTrends(std::vector<int> monthlyPassengers)

{
    // Placeholder: Assume steady growth


    return monthlyPassengers;
}

// Function to optimize fuel consumption using AI


double optimizeFuelConsumption(double distance, double speed, double weight)


{
    return (distance / speed) * weight * 0.9;

    // Example: AI-optimized efficiency
}

// Function to predict ticket sales for holidays


int predictHolidayTicketSales(int averageDailySales, double holidayFactor)


{
    return static_cast<int>(averageDailySales * holidayFactor);


}

// Function to provide AI-generated insights for train routes


std::string getAIInsightsForRoutes(std::string routeName)


{
    return "Route shows potential for 15% growth during holiday season.";

     // Placeholder
}

// Function to predict train delay based on weather and route conditions


double estimateTotalOperationalTime(double dailyHours, int operationalDays)
{


    return dailyHours * operationalDays;


}

// Function to assign priority to high-traffic stations


std::vector<std::string> assignStationPriority(std::vector<std::string> stations, std::vector<int> dailyPassengers)
{


    return stations;

     // Placeholder
}

// Function to track real-time train occupancy on a schedule
std::vector<int> getRealTimeOccupancy(std::vector<int> trainIds)
{
    return {85, 90, 78}; // Placeholder occupancy rates
}

// Function to estimate turnaround time between trips


double calculateTurnaroundTime(double tripDuration, double maintenanceTime)
{


    return tripDuration + maintenanceTime;
}

// Function to log missed train connections


bool logMissedConnections(int trainId, int affectedPassengers)
{
    return true;

     // Placeholder: Assume successful logging
}

// Function to evaluate route efficiency


double evaluateRouteEfficiency(double totalPassengers, double averageDelay)
{

    return totalPassengers / (averageDelay + 1);
    // Placeholder calculation
}


// Function to forecast ticket sales for a train


int forecastTicketSales(int currentSales, double growthFactor)
{



    return static_cast<int>(currentSales * (1 + growthFactor));
}

// Function to predict train delay based on route conditions


double predictTrainDelay(double routeComplexity, double trafficDensity)
{


    return routeComplexity * trafficDensity / 10.0;

     // Placeholder
}

// Function to analyze fuel efficiency trends


std::vector<double> analyzeFuelEfficiency(std::vector<double> fuelData)
{


    return fuelData;

    // Placeholder: Return as-is
}

// Function to calculate average revenue per trip


double calculateAverageRevenuePerTrip(double totalRevenue, int trips)
{


    return totalRevenue / trips;


}

// Function to detect underutilized trains


std::vector<int> detectUnderutilizedTrains(std::vector<int> trainIds, std::vector<double> occupancyRates, double threshold)
{


    std::vector<int> underutilized;


    for (size_t i = 0; i < trainIds.size(); ++i)
    {


        if (occupancyRates[i] < threshold)
        {

            underutilized.push_back(trainIds[i]);


        }


    }
    return underutilized;


}

// Function to log operational performance metrics


bool logOperationalMetrics(int trainId, double fuelEfficiency, double averageSpeed)
{

    return true; // Placeholder


}

// Function to identify peak travel hours


std::vector<int> identifyPeakTravelHours(std::vector<int> hourlyPassengerCounts)
{


    return {8, 18};

    // Placeholder: Morning and evening peaks
}

// Function to assign a train crew to a specific train


bool assignCrewToTrain(int trainId, int crewId)
{
    return true;

    // Placeholder: Assume crew assignment is successful
}

// Function to track crew working hours


double trackCrewWorkingHours(int crewId)
{
    return 8.0;

    // Placeholder: Assume crew works 8 hours per shift
}

// Function to schedule a crew's shift for a particular train


bool scheduleCrewShift(int crewId, int trainId, std::string shiftStartTime, std::string shiftEndTime)
{
    return true;

    // Placeholder: Assume crew shift scheduled successfully
}

// Function to check the availability of a crew member for a shift


bool checkCrewAvailability(int crewId)
{
    return true;

    // Placeholder: Assume crew member is available
}

// Function to log a crew member's performance during a shift


bool logCrewPerformance(int crewId, std::string performanceDetails)
{
    return true;

    // Placeholder: Assume performance is logged successfully
}

// Function to monitor crew member fatigue levels based on working hours

bool monitorCrewFatigue(int crewId)
{
    return false;

    // Placeholder: Assume no fatigue detected
}

// Function to issue a report on crew performance for a particular train


std::string generateCrewPerformanceReport(int crewId, int trainId)
{
    return "Crew performance is satisfactory";

    // Placeholder: Placeholder report
}

// Function to assign specific duties to each crew member on the train


bool assignCrewDuties(int crewId, std::string dutyDescription)
{
    return true;

     // Placeholder: Assume duties assigned successfully
}

// Function to monitor crew training progress


bool monitorCrewTrainingProgress(int crewId)


{
    return true;

    // Placeholder: Assume crew is well-trained
}

// Function to synchronize data between the train's onboard system and the central database


bool synchronizeTrainData(int trainId)
{
    return true;

    // Placeholder: Assume data synchronization is successful
}

// Function to back up the train's operational data


bool backupTrainData(int trainId)
{
    return true; // Placeholder: Assume data backup is successful

}

// Function to restore backup data to a train's onboard system


bool restoreBackupData(int trainId)
{
    return true;

    // Placeholder: Assume data restoration is successful
}

// Function to check the status of data synchronization with the central system


bool checkDataSynchronizationStatus(int trainId)
{
    return true;

     // Placeholder: Assume data synchronization is up to date
}

// Function to log data synchronization events for troubleshooting


bool logDataSynchronizationEvent(int trainId, std::string eventDetails)
{
    return true;

    // Placeholder: Assume event logged successfully
}

// Function to schedule regular backups for train operational data


bool scheduleRegularBackups(int trainId)


{
    return true;

    // Placeholder: Assume backup schedule set successfully
}

// Function to ensure data integrity after synchronization


bool verifyDataIntegrity(int trainId)
{
    return true;

    // Placeholder: Assume data integrity is verified
}

// Function to update onboard software with the latest patches


bool updateOnboardSoftware(int trainId)
{
    return true;

    // Placeholder: Assume software update successful
}

// Function to audit train data to ensure compliance with regulations


bool auditTrainData(int trainId)
{
    return true; // Placeholder: Assume audit passed


}

// Function to check the consistency of data across multiple systems


bool checkDataConsistencyAcrossSystems(int trainId)
{

    return true; // Placeholder: Assume data consistency verified
}
// Function to monitor the train's real-time performance metrics


bool monitorTrainPerformance(int trainId)
{
    return true; // Placeholder: Assume performance is being monitored


}

// Function to calculate fuel efficiency for each train
double calculateFuelEfficiency(int trainId, double distanceTraveled, double fuelConsumed)


{
    return distanceTraveled / fuelConsumed;

    // Placeholder: Return calculated fuel efficiency
}

// Function to track train's average speed over the past week


double trackAverageSpeed(int trainId, std::vector<double> dailySpeeds)


{
    double totalSpeed = 0;


    for (double speed : dailySpeeds)


    {
        totalSpeed += speed;

    }
    return totalSpeed / dailySpeeds.size();

    // Placeholder
}

// Function to check train's carbon footprint based on fuel usage


double calculateCarbonFootprint(int trainId, double fuelConsumed)


{
    return fuelConsumed * 2.68;

    // Placeholder: CO2 emissions per liter of fuel (example)
}

// Function to generate a report on train's punctuality over the last month


std::string generatePunctualityReport(int trainId, std::vector<int> delays)
{
    double totalDelay = 0;

    for (int delay : delays)


    {
        totalDelay += delay;


    }
    return "Total delay: " + std::to_string(totalDelay) + " minutes";

     // Placeholder
}

// Function to track train's maintenance history and costs


std::vector<std::string> trackMaintenanceCosts(int trainId)
{


    return {"Maintenance 1: $500", "Maintenance 2: $750"};

     // Placeholder
}

// Function to generate monthly performance report for train

std::string generateMonthlyPerformanceReport(int trainId)

{
    return "Train performance is above average";


    // Placeholder
}

// Function to track average occupancy rates over multiple trips

double trackAverageOccupancyRate(int trainId, std::vector<double> occupancyRates)
{
    double totalOccupancy = 0;


    for (double rate : occupancyRates)


    {
        totalOccupancy += rate;


    }
    return totalOccupancy / occupancyRates.size();

    // Placeholder
}

// Function to analyze train's wear and tear over time


std::string analyzeTrainWearAndTear(int trainId)


{
    return "Train is in good condition";

    // Placeholder
}
// Function to check ticket availability for a specific train

bool checkTicketAvailability(int trainId)

{
    return true;

    // Placeholder: Assume tickets are available
}

// Function to book a ticket for a passenger on a specific train


bool bookTicket(int trainId, int passengerId)


{
    return true; // Placeholder: Assume ticket booking successful
}

// Function to issue a refund for a canceled ticket


bool issueRefund(int ticketId)
{

    return true;

    // Placeholder: Assume refund issued successfully
}

// Function to calculate the price of a ticket based on distance


double calculateTicketPrice(double distance)
{
    return distance * 0.5;

    // Placeholder: Example price calculation


}

// Function to check if a passenger is eligible for a discount


bool checkDiscountEligibility(int passengerId)


{
    return true;

     // Placeholder: Assume eligibility verified
}

// Function to reserve a seat for a passenger
bool reserveSeat(int trainId, int passengerId)


{
    return true;

    // Placeholder: Assume seat reserved successfully
}

// Function to generate a detailed ticket for a passenger


std::string generateTicket(int ticketId)


{
    return "Ticket ID: " + std::to_string(ticketId);

    // Placeholder: Placeholder ticket
}

// Function to check seat availability for a group of passengers


bool checkGroupSeatAvailability(int groupId, int groupSize)
{
    return true;

     // Placeholder: Assume group seats are available
}

// Function to cancel a reserved ticket


bool cancelTicket(int ticketId)


{
    return true;

    // Placeholder: Assume ticket canceled successfully
}

// Function to issue a boarding pass for a passenger


std::string issueBoardingPass(int ticketId)


{
    return "Boarding Pass for Ticket ID: " + std::to_string(ticketId);

     // Placeholder
}


// Function to calculate the number of stops a train will make during its journey


int calculateTrainStops(int trainId)


{
    return 5;

    // Placeholder: Assume 5 stops during the journey
}

// Function to check if the train is operating within the required safety parameters


bool checkTrainSafetyParameters(int trainId)


{


    return true;

     // Placeholder: Assume safety parameters are met
}

// Function to check if the train is operating on a high-speed route

bool isTrainOnHighSpeedRoute(int trainId)

{


    return true;



    // Placeholder: Assume the train is on a high-speed route


}

// Function to monitor train's battery life for electric trains


double monitorTrainBatteryLife(int trainId)

{


    return 80.0;

    // Placeholder: Assume battery is at 80% capacity


}

// Function to calculate estimated fuel savings on an eco-friendly route


double calculateFuelSavings(int trainId, double fuelConsumption)
{

    return fuelConsumption * 0.1;


     // Placeholder: 10% fuel savings

}

// ----------------------------------------
// Function to track the maintenance history for a specific train
// This function returns a list of maintenance logs for a given train


// Placeholder return value for simplicity
// ----------------------------------------
std::vector<std::string> getMaintenanceHistory(int trainId)


{
    // Maintenance records for the given trainId
    return {
        "Maintenance 1: Oil change",
        "Maintenance 2: Brake check"


    };
}


// ----------------------------------------
// Function to schedule maintenance based on the train's mileage
// This function checks if the mileage has crossed a certain threshold and schedules maintenance accordingly
// The mileage threshold for maintenance is 50,000 km in this example


// ----------------------------------------
bool scheduleMileageBasedMaintenance(int trainId, double mileage)



{
    // If the mileage exceeds 50,000 km, maintenance is scheduled
    if (mileage > 50000.0)



    {
        return true; // Maintenance scheduled
    }
    else



    {
        return false;


        // No maintenance required
    }
}


// Function to order spare parts for the train's maintenance
// This function takes the part name and quantity, and returns a success flag
// The actual implementation would involve inventory checks and supplier systems
// ----------------------------------------


bool orderSpareParts(int trainId, std::string partName, int quantity)


{
    // Placeholder logic to simulate spare part order


    std::cout << "Ordered " << quantity << " of " << partName << " for train " << trainId << std::endl;


    return true; // Assume spare parts ordered successfully
}


// ----------------------------------------
// Function to track the status of the ordered spare parts
// This function checks whether the spare parts have been shipped or are pending
// Placeholder logic for simplicity
// ----------------------------------------
std::string trackSparePartsOrder(int orderId)


{
    // Placeholder tracking information

    return "Spare parts ordered and shipped";


}


// ----------------------------------------
// Function to check the status of the train's exhaust system
// Checks if the exhaust system is functioning as expected
// Placeholder return value for simplicity
// ----------------------------------------
bool checkExhaustSystem(int trainId)



{
    // Assume exhaust system is working fine

    return true;

}


// ----------------------------------------
// Function to perform an emergency inspection of the train's critical systems
// This function simulates a quick check of critical systems in case of emergencies
// Placeholder for simplicity
// ----------------------------------------
bool performEmergencyInspection(int trainId)

{
    // Placeholder logic to simulate emergency inspection

    std::cout << "Emergency inspection performed for train " << trainId << std::endl;

    return true;

    // Assume inspection passed
}


// ----------------------------------------
// Function to calculate the expected lifespan of the train's engine

// This function estimates the lifespan based on current usage patterns
// Placeholder logic with example values
// ----------------------------------------

double calculateEngineLifespan(int trainId)


{


    // Estimate lifespan in years based on the current usage

    return 15.0;

    // Placeholder: Assume the engine lasts for 15 years
}

// Function to track the train's location based on its route and current position


std::string trackTrainLocation(int trainId)


{
    return "Train " + std::to_string(trainId) + " is at station 5.";


}


// Function to update the status of a train (e.g., "On Time", "Delayed", "Cancelled")
bool updateTrainStatus(int trainId, std::string newStatus)
{


    std::cout << "Updating status of train " << trainId << " to " << newStatus << std::endl;
    return true;


}


// Function to check if the train is running on time


bool isTrainOnTime(double scheduledArrivalTime, double actualArrivalTime)


{

    if (actualArrivalTime <= scheduledArrivalTime)

    {

        std::cout << "Train is on time." << std::endl;


        return true;


    }

    else


    {


        std::cout << "Train is delayed." << std::endl;

        return false;


    }
}


// Function to estimate the time required for the train to reach its destination


double estimateArrivalTime(double currentSpeed, double remainingDistance)


{
    double estimatedTime = remainingDistance / currentSpeed;

    std::cout << "Estimated time of arrival: " << estimatedTime << " hours." << std::endl;

    return estimatedTime;


}

// Function to assign a staff member to a specific duty on the train


bool assignStaffToDuty(int staffId, std::string duty)

{
    std::cout << "Assigning staff member " << staffId << " to " << duty << std::endl;

    return true;
}

// Function to check if a train is equipped with Wi-Fi service



// Function to check the current status of the train (e.g., "On Time", "Delayed", "Cancelled")
std::string checkTrainStatus(int trainId)
{
    // logic to check the status of a train


    if (trainId % 2 == 0)
    {
        return "On Time";
         // Even-numbered trains are always on time

    }

    else

    {
        return "Delayed";
    // Odd-numbered trains are delayed


    }
}


// Function to calculate the fuel efficiency of the train based on distance and fuel used

double calculateFuelEfficiency(double distance, double fuelUsed)


{
    return distance / fuelUsed;

      // Fuel Efficiency = Distance / Fuel Used
}


// Function to check if a train is operating on a specific holiday (e.g., Christmas, New Year)


bool isTrainOperatingOnHoliday(int trainId, std::string holiday)

{
    // logic to check if a train is operating on a holiday

    if (holiday == "Christmas" || holiday == "New Year")

    {
        return true;

    // Assume all trains are operating on holidays

    }

    else


    {
        return false;
    // Trains don't operate on non-holidays


    }
}


// Function to check the maximum capacity of a train's passenger cars
int getTrainCapacity(int trainId)
{
    // Dummy logic to return the capacity based on train type
    if (trainId % 2 == 0)
    {
        return 300;  // Even-numbered trains have a higher capacity
    }
    else
    {
        return 150;  // Odd-numbered trains have a lower capacity
    }
}


// Function to update the schedule for a train
bool updateTrainSchedule(int trainId, std::string newDepartureTime)
{
    // Dummy logic to update the schedule
    std::cout << "Updating schedule for train " << trainId << " to depart at " << newDepartureTime << std::endl;
    return true;
}


// Function to calculate the total fare for a train journey including base fare and additional services
double calculateTotalFare(double baseFare, double additionalServices)
{
    return baseFare + additionalServices;  // Total fare = Base fare + Additional services
}


// Function to assign a train crew member to a shift
bool assignCrewMemberToShift(int crewId, std::string shift)
{
    // logic to assign a crew member to a shift

    std::cout << "Assigning crew member " << crewId << " to the " << shift << " shift." << std::endl;


    return true;
}


// Function to simulate the departure of a train


bool departTrain(int trainId, std::string departureTime)
{
    // logic to simulate train departure

    std::cout << "Train " << trainId << " departing at " << departureTime << std::endl;


    return true;
}

// Function to check if the train is running on a special route
bool isSpecialRoute(int trainId)
{
    // Dummy logic for checking if the train is running on a special route


    if (trainId % 3 == 0)

    {
        return true;

          // Train running on a special route if trainId is divisible by 3
    }
    else


    {
        return false;

         // Not on a special route
    }
}


// Function to check if a train has been cleaned after its last trip

bool isTrainClean(int trainId)
{
    // logic to check if the train is clean

    return (trainId % 2 == 0);

    // Even-numbered trains are clean
}


// Function to calculate the estimated time of arrival at the next station

double calculateNextStationArrivalTime(double currentSpeed, double remainingDistance)



{
    return remainingDistance / currentSpeed;

     // Time = Distance / Speed
}


// Function to check the weather condition at a train's current location

std::string getTrainWeatherCondition(int trainId)
{
    // logic to simulate weather condition


    return (trainId % 2 == 0) ? "Clear" : "Rainy";

    // Even-numbered trains have clear weather
}





// Function to check if a train has sufficient fuel for the entire trip


bool isFuelSufficient(double fuelRequired, double availableFuel)

{
    return availableFuel >= fuelRequired;

    // Fuel is sufficient if available fuel is greater than required
}


// Function to simulate a train stopping at a station


bool stopAtStation(int trainId, std::string station)


{
    // logic to simulate the train stopping at a station


    std::cout << "Train " << trainId << " is stopping at station " << station << std::endl;

    return true;
}


// Function to simulate a delay for a train due to external conditions

bool simulateDelay(int trainId, double delayTime)
{
    //  logic to simulate a train delay

    std::cout << "Train " << trainId << " is delayed by " << delayTime << " minutes." << std::endl;

    return true;
}


// Function to check if a train has a restaurant service


bool isRestaurantAvailable(int trainId)

{
    //  logic to check if restaurant service is available

    return (trainId % 2 == 0);

    // Even-numbered trains have restaurant service
}


// Function to perform emergency maintenance on the train


bool performEmergencyMaintenance(int trainId)

{

    // logic to simulate emergency maintenance

    std::cout << "Performing emergency maintenance on train " << trainId << std::endl;

    return true;
}


// Function to update the maintenance schedule for a train


bool updateMaintenanceSchedule(int trainId, std::string maintenanceDate)

{
    // logic to update maintenance schedule

    std::cout << "Updating maintenance schedule for train " << trainId << " to " << maintenanceDate << std::endl;

    return true;
}


// Function to check if a train is due for a safety inspection

bool isSafetyInsspectionDue(int trainId)

{
    // logic to check if safety inspection is due


    return (trainId % 2 != 0);

     // Odd-numbered trains are due for safety inspections
}


// Function to calculate the number of days until the next maintenance

int daysUntilNexttMaintenance(int lastMaintenanceDaysAgo)
{
    int maintenanceInterval = 30;

    // Maintenance occurs every 30 days

    return maintenanceInterval - lastMaintenanceDaysAgo;

}


// Function to assign maintenance workers to a specific train

bool assignMainttenanceWorkerToTrain(int workerId, int trainId)

{

    std::cout << "Assigning maintenance worker " << workerId << " to train " << trainId << std::endl;

    return true;
}

bool departTrainn(int trainId, std::string departureTime)
{
    // logic to simulate train departure

    std::cout << "Train " << trainId << " departing at " << departureTime << std::endl;


    return true;
}

// Function to check if the train is running on a special route
bool isSpecialRoutte(int trainId)
{
    // Dummy logic for checking if the train is running on a special route


    if (trainId % 3 == 0)

    {
        return true;

          // Train running on a special route if trainId is divisible by 3
    }
    else


    {
        return false;

         // Not on a special route
    }
}


// Function to check if a train has been cleaned after its last trip

bool isTrainCleann(int trainId)
{
    // logic to check if the train is clean

    return (trainId % 2 == 0);

    // Even-numbered trains are clean
}


// Function to calculate the estimated time of arrival at the next station

double calculateNexttStationArrivalTime(double currentSpeed, double remainingDistance)



{
    return remainingDistance / currentSpeed;

     // Time = Distance / Speed
}


// Function to check the weather condition at a train's current location

std::string getTrainnWeatherCondition(int trainId)
{
    // logic to simulate weather condition


    return (trainId % 2 == 0) ? "Clear" : "Rainy";

    // Even-numbered trains have clear weather
}





// Function to check if a train has sufficient fuel for the entire trip


bool isFuelSuffiicient(double fuelRequired, double availableFuel)

{
    return availableFuel >= fuelRequired;

    // Fuel is sufficient if available fuel is greater than required
}


// Function to simulate a train stopping at a station


bool stopAtStaation(int trainId, std::string station)


{
    // logic to simulate the train stopping at a station


    std::cout << "Train " << trainId << " is stopping at station " << station << std::endl;

    return true;
}


// Function to simulate a delay for a train due to external conditions

bool simulateDeelay(int trainId, double delayTime)
{
    //  logic to simulate a train delay

    std::cout << "Train " << trainId << " is delayed by " << delayTime << " minutes." << std::endl;

    return true;
}


// Function to check if a train has a restaurant service


bool isRestauranttAvailable(int trainId)

{
    //  logic to check if restaurant service is available

    return (trainId % 2 == 0);

    // Even-numbered trains have restaurant service
}


// Function to perform emergency maintenance on the train


bool performEmergenncyMaintenance(int trainId)

{

    // logic to simulate emergency maintenance

    std::cout << "Performing emergency maintenance on train " << trainId << std::endl;

    return true;
}


// Function to update the maintenance schedule for a train


bool updateMaintennanceSchedule(int trainId, std::string maintenanceDate)

{
    // logic to update maintenance schedule

    std::cout << "Updating maintenance schedule for train " << trainId << " to " << maintenanceDate << std::endl;

    return true;
}


// Function to check if a train is due for a safety inspection

bool isSafetyInnspectionDue(int trainId)

{
    // logic to check if safety inspection is due


    return (trainId % 2 != 0);

     // Odd-numbered trains are due for safety inspections
}


// Function to calculate the number of days until the next maintenance

int daysUntillNexttMaintenance(int lastMaintenanceDaysAgo)
{
    int maintenanceInterval = 30;

    // Maintenance occurs every 30 days

    return maintenanceInterval - lastMaintenanceDaysAgo;

}


// Function to assign maintenance workers to a specific train

bool assignnMaintenanceWorkerToTrain(int workerId, int trainId)

{

    std::cout << "Assigning maintenance worker " << workerId << " to train " << trainId << std::endl;

    return true;
}


bool cancellTicket(int ticketId)


{
    return true;

    // Placeholder: Assume ticket canceled successfully
}

// Function to issue a boarding pass for a passenger


std::string issueBoardingPasss(int ticketId)


{
    return "Boarding Pass for Ticket ID: " + std::to_string(ticketId);

     // Placeholder
}


// Function to calculate the number of stops a train will make during its journey


int calculateeTrainStops(int trainId)


{
    return 5;

    // Placeholder: Assume 5 stops during the journey
}

// Function to check if the train is operating within the required safety parameters


bool checkTraiinSafetyParameters(int trainId)


{


    return true;

     // Placeholder: Assume safety parameters are met
}

// Function to check if the train is operating on a high-speed route

bool isTrainOnHighSspeedRoute(int trainId)

{


    return true;



    // Placeholder: Assume the train is on a high-speed route


}

// Function to monitor train's battery life for electric trains


double monitorTrainnBatteryLife(int trainId)

{


    return 80.0;

    // Placeholder: Assume battery is at 80% capacity


}

// Function to calculate estimated fuel savings on an eco-friendly route


double calculateFuellSavings(int trainId, double fuelConsumption)
{

    return fuelConsumption * 0.1;


     // Placeholder: 10% fuel savings

}

// ----------------------------------------
// Function to track the maintenance history for a specific train
// This function returns a list of maintenance logs for a given train


// Placeholder return value for simplicity
// ----------------------------------------
std::vector<std::string> getMaiintenanceHistory(int trainId)


{
    // Maintenance records for the given trainId
    return {
        "Maintenance 1: Oil change",
        "Maintenance 2: Brake check"


    };
}


// ----------------------------------------
// Function to schedule maintenance based on the train's mileage
// This function checks if the mileage has crossed a certain threshold and schedules maintenance accordingly
// The mileage threshold for maintenance is 50,000 km in this example


// ----------------------------------------
bool scheduleMileageBasedMainntenance(int trainId, double mileage)



{
    // If the mileage exceeds 50,000 km, maintenance is scheduled
    if (mileage > 50000.0)



    {
        return true; // Maintenance scheduled
    }
    else



    {
        return false;


        // No maintenance required
    }
}


// Function to order spare parts for the train's maintenance
// This function takes the part name and quantity, and returns a success flag
// The actual implementation would involve inventory checks and supplier systems
// ----------------------------------------
