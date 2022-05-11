#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

// lớp người chơi
class player{
    private:
        char name[10];
        int point;
        int answer;
        float timing;

    public:
        void nameInput();
        void answerInput();

};

void player::nameInput(){
    cout<<"Player's name :";
    cin >>name;
    cout<<name<<", are ready ?"<<"\n";
};

void player::answerInput(){
    cin >>answer;
}

//lớp câu hỏi
class question{
    private:

    public:

};

int main(){
    //làm sạch terminal
    system("cls");

    //khởi tạo người chơi mặc định
    player p1;
    p1.nameInput(); //người chơi nhập tên
    //Sleep(1000);

    //bắt đầu trò chơi
    while(true){ 

        cout<<"Do you want to continue? (Y/N)"<<"\n"; //hỏi player có muốn tiếp tục chơi hay không
        char continiu;
        cin >>continiu;
        if(continiu=='N' || continiu=='n') break; //thoát khởi trò chơi
        else continue; //tiếp tục chơi
    }
    
    cout<<"Thank you for your times";
    return 0;
}