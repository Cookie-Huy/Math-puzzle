#include <iostream>
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
        int getAnswerInput();
        void getTime(float t);
        void getPoint();
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
    cout<<"Player's answer : "<<answer<<"\n";
}

void player::getTime(float t){
    timing = t;
    cout<<"Your time : "<<timing<<" seconds\n";
}

int player::getAnswerInput(){
    return answer;
}

void player::getPoint(){
    system("cls");
    point++;
    cout<<"Points : "<<point;
    Sleep(1000);
}


void count_down(){
    // đếm ngược để người chơi chuẩn bị
    for(int i=3;i>0;i--){
        system("cls");
        cout<<i;
        Sleep(1000);
    }
    system("cls");
    cout<<"---Start---";;
    Sleep(1000);
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
        int getResult();

};

void question::generateQuestion(){
    system("cls");
    a = rand()%10;
    b = rand()%10;
    result = a + b;
    cout<<a<<" + "<<b<<" = ";
}

int question::getResult(){
    return result;
}


int main(){
    //làm sạch terminal
    system("cls");
    
    //khởi tạo người chơi mặc định
    player p1;
    p1.nameInput(); //người chơi nhập tên
    
    question q1; // khởi tạo câu hỏi mặc định

    
    
    
    //bắt đầu trò chơi
    while(true){ 
        
        start_f(); // bắt đầu vào game
        count_down(); // chuẩn bị vào game
            
        while(true){
            auto start = std::chrono::steady_clock::now(); //bắt đầu tính giờ
                while(true){
                q1.generateQuestion(); //khởi tạo câu hỏi
                int temp_result = q1.getResult();

                p1.answerInput(); //người chơi nhập câu trả lời
                int temp_answer = p1.getAnswerInput();
                Sleep(1000);

                if(temp_answer == temp_result){
                    p1.getPoint();
                } else {
                    break;
                }
                }

            
            system("cls");
            // tính thgian kết thúc lượt chơi và in ra
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration <double> t = end - start;
            float time = t.count();
            p1.getTime(time);
        }
        


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