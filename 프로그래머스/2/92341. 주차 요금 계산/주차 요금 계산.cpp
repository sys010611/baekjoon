#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;
map<int, vector<int>> historyPerCars;

vector<int> solution(vector<int> fees, vector<string> records) {    
    vector<int> result;

    for(auto record: records)
    {
        // 문자열을 스트림화
        stringstream ss(record);

        // 스트림을 통해, 문자열을 공백 분리해 변수에 할당
        string time, carNumber, action;
        ss >> time >> carNumber >> action;
        int carNo = stoi(carNumber);
        
        // time을 단일 int로 변환
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 5));
        int newTime = hour*60 + min;
        
        if(historyPerCars.find(carNo) == historyPerCars.end())
        {
            historyPerCars[carNo] = vector<int>();
        }
        historyPerCars[carNo].push_back(newTime);
    }
    for(auto& history:  historyPerCars)
    {
        if(history.second.size()%2 == 1)
        {
            history.second.push_back(23*60 + 59);
        }
    }
    
    
    for(auto history:historyPerCars)
    {
        int number = history.first;
        vector<int> times = history.second;
        
        // cout << "number: " << number << endl;
        // cout << "times : ";
        // for(auto time:times)
        //     cout << time << " ";
        // cout << endl;
        
        int wholeTime = 0;
        for(int i=0;i<times.size(); i+=2)
        {
            wholeTime += times[i+1] - times[i];
        }
        // cout << "wholeTime : " << wholeTime << endl;
        
        if(wholeTime <= fees[0])
        {
            result.push_back(fees[1]);
            // cout << "fee : " << fees[1] << endl;
        }
        else
        {
            int overTime = wholeTime - fees[0];
            int overFee = ceil((float)overTime / fees[2]) * fees[3];
            result.push_back(fees[1] + overFee);
            
            // cout << "fee : " << fees[1] + overFee << endl;
        }
    }
    
    return result;
}