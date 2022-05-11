#include <bits/stdc++.h>
#include <windows.h>
#include <chrono>
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
        void getTime(float t);
        void checkAnswer();
};

void player::nameInput(){
    // nhập tên người chơi
    cout<<"Player's name : ";
    cin >>name;
    cout<<name<<", are ready ?\n";
};

void player::answerInput(){
    // nhập câu trả lời của người chơi
    cin >>answer;
}

void player::getTime(float t){
    timing = t;
    cout<<"Your time : "<<timing<<" seconds\n";
}


void count_down(){
    // đếm ngược để người chơi chuẩn bị
    for(int i=5;i>0;i--){
        system("cls");
        cout<<i;
        Sleep(1000);
    }
    system("cls");
    cout<<"---Start---"<<"\n";
}

void start_f(){
    // nhấn để bắt đầu chơi
    cout<<"Press to start (Y/N)"<<"\n";
    char start;
    while(true){
        cin >>start;
        if(start == 'Y' || start =='y') break;
        else continue;
    }
};


//lớp câu hỏi
class question{
    private:
        int a,b,c,d;
        int result;
    public:
        void generateQuestion();
        friend void player::checkAnswer(); 

};

void generateQuestion(){
    system("cls");
    int a = rand();
    int b = rand();
    cout<<a<<" + "<<b<<" = ";
}
int main(){
    //làm sạch terminal
    system("cls");
    
    //khởi tạo người chơi mặc định
    player p1;
    p1.nameInput(); //người chơi nhập tên
    //Sleep(1000);
    
    //bắt đầu trò chơi
    while(true){ 
        
        start_f(); // bắt đầu vào game
        count_down(); // chuẩn bị vào game
        auto start = std::chrono::steady_clock::now(); //bắt đầu tính giờ
        generateQuestion(); //khởi tạo câu hỏi
        p1.answerInput(); //người chơi nhập câu trả lời

        
        system("cls");
        // tính thgian kết thúc lượt chơi và in ra
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration <double> t = end - start;
        float time = t.count();
        p1.getTime(time);
        


        //hỏi player có muốn tiếp tục chơi hay không
        cout<<"Do you want to continue? (Y/N)"<<"\n"; 
        char continiu;
        cin >>continiu;
        system("cls");
        if(continiu=='N' || continiu=='n') break; //thoát khởi trò chơi
        else continue; //tiếp tục chơi
    }
    
    
    
    cout<<"Thank you for your times";
    return 0;
}