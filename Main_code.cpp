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
        int getAnswerInput();
        void getTime(float t);
        void getPoint();
};

void player::nameInput(){
    // nhập tên người chơi
    cout<<"Player's name : ";
    cin >>name;
    
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
    cout<<"Corrected\n";
    point++;
    cout<<"Points : "<<point;
    Sleep(500);
}


void count_down(){
    // đếm ngược để người chơi chuẩn bị
    for(int i=3;i>0;i--){
        system("cls");
        cout<<i;
        Sleep(500);
    }
    system("cls");
    cout<<"---Start---";;
    Sleep(500);
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
        int diff;
    public:
        void generateQuestion(int diff);
        int getResult();
        int chooseLevel();
        
};

void question::generateQuestion(int diff){
    system("cls");
    a = rand()%20;
    b = rand()%20;
    c = rand()%20;
    if(diff == 1){
        result = a + b;
        cout<<a<<" + "<<b<<" = ";
    } else if(diff == 2){
        result = a + b + c;
        cout<<a<<" + "<<b<<" + "<<c<<" = ";
    } else if(diff == 3){
        result = a * b;
        cout<<a<<" x "<<b<<" = ";
    }
}

int question::getResult(){
    return result;
}

int question::chooseLevel(){
    cout<<"Chosse level: Easy - Medium - Difficult (type 1 / 2 / 3 )\n";
    cin >> diff;
    return diff;
}


int main(){
    //làm sạch terminal
    system("cls");
    
    //khởi tạo người chơi mặc định
    player p1;
    //người chơi nhập tên
    p1.nameInput(); 
    // khởi tạo câu hỏi mặc định
    question q1; 
    //chọn độ khó cho game
    int diff_level = q1.chooseLevel(); 
    
    //bắt đầu trò chơi
    while(true){ 
        
        int quizNumber = 10;
        // bắt đầu vào game
        start_f();
        // chuẩn bị vào game
        count_down(); 
            
        while(true){
            //bắt đầu tính giờ
            auto start = std::chrono::steady_clock::now(); 
            while(quizNumber--){
                //khởi tạo câu hỏi
                q1.generateQuestion(diff_level); 
                int temp_result = q1.getResult();
                //người chơi nhập câu trả lời
                p1.answerInput();
                int temp_answer = p1.getAnswerInput();
                Sleep(300);

                if(temp_answer == temp_result){
                    p1.getPoint();                    
                } else {
                    
                    cout <<"Wrong answer.\nThe answer is "<<temp_answer;
                    Sleep(500);
                }
            }

            system("cls");
            // tính thgian kết thúc lượt chơi và in ra
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration <double> t = end - start;
            float time = t.count();
            p1.getTime(time);
            break;
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