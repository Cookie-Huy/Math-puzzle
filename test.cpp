#include <iostream>
#include <windows.h>
#include <chrono>
using namespace std;

// lớp người chơi
class player{
    private:
        char name[10];
        int score=0;
        int answer;
        float timing;
    public:
        void nameInput();
        void answerInput();
        int getAnswerInput();
        void getTime(float t);
        void Score();
        void getScore();
        void reset();
        int ReS();
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

void player::getTime(float t)
{
    timing = t;
    cout<<"Your time : "<<timing<<" seconds\n";
}

int player::getAnswerInput()
{
    return answer;
}

void player::getScore()
{
    system("cls");
    score++;
}
void player::Score()
{    
    cout<<"Score : "<<score;
    Sleep(1000);
}

void player::reset()
{
    score=0;
}
int player::ReS(){
    return score;
}

void count_down()
{
    // đếm ngược để người chơi chuẩn bị
    for(int i=3;i>0;i--)
    {
        system("cls");
        cout<<" --- "<< i<<" --- ";
        Sleep(1000);
    }
    system("cls");
    cout<<" --- Start --- ";;
    Sleep(1000);
}


//lớp câu hỏi
class question
{
    private:
        int a,b,c,d;
        int result;
    public:
        void generateQuestion1();
        void generateQuestion2();
        int getResult();

};

void question::generateQuestion1()
{
    system("cls");
    a = (rand()&1 ? -1:1) * rand()%10;
    b = (rand()&1 ? -1:1) * rand()%10;
    result = a + b;
    cout<<a<<" + "<<b<<" = ";
}

void question::generateQuestion2()
{
    system("cls");
    a = (rand()&1 ? -1:1) * rand()%10;
    b = (rand()&1 ? -1:1) * rand()%10;
    c = (rand()&1 ? -1:1) * rand()%10;
    result = (a + b) * c;
    cout<<"( "<<a<<" + "<<b<<" ) * "<<c<<" = ";
}

int question::getResult()
{
    return result;
}

void CorrectAns(){
    int x=rand()%4+1;
    switch(x){
        case 1: cout<<"~ ~ ~ Correct ~ ~ ~ ";break;
        case 2: cout<<"~ ~ ~ Welldone ~ ~ ~ ";break;
        case 3: cout<<"~ ~ ~ Goodjob ~ ~ ~ ";break;
        case 4: cout<<"~ ~ ~ That's right ! ~ ~ ~ ";break;                        
    }
    Sleep(1000);
}

void IncorrectAns(){
    int x=rand()%4+1;
    switch(x){
        case 1: cout<<"~ ~ ~ Incorrect ~ ~ ~ ";break;
        case 2: cout<<"~ ~ ~ Wrong!!!! ~ ~ ~ ";break;
        case 3: cout<<"~ ~ ~ Oops ~ ~ ~ ";break;
        case 4: cout<<"~ ~ ~ Game over ~ ~ ~ ";break;                        
    }
    Sleep(1000);
}

int main()
{ 
    system("cls"); //làm sạch terminal

    while(true)
    {    
        player p1; //khởi tạo người chơi mặc định

        p1.nameInput(); //người chơi nhập tên
    
        question q1; // khởi tạo câu hỏi mặc định

    
        cout<<"Press to start (Y/N)"<<"\n"; // bắt đầu vào game
        char start;
        while(true)
        {
            cin >>start;
            if(start == 'Y' || start =='y') break;
            else
            goto ketthuc;
        }
        system("cls");
    

        count_down(); // chuẩn bị vào game
            
        while(true)
            {
                auto start = std::chrono::steady_clock::now(); //bắt đầu tính giờ
                while(true)
                {   
                    if ( p1.ReS() > 4 ){ //khởi tạo câu hỏi
                        q1.generateQuestion2();
                    }
                    else{
                    q1.generateQuestion1(); 
                    }
                    int temp_result = q1.getResult();

                    p1.answerInput(); //người chơi nhập câu trả lời
                    int temp_answer = p1.getAnswerInput();
                    Sleep(1000);

                    if(temp_answer == temp_result)
                    {   
                        CorrectAns();
                        p1.getScore();
                        p1.Score();
                    }
                    else 
                    {
                        IncorrectAns();
                        break;
                    }
                }

            
            system("cls");
            // tính thgian kết thúc lượt chơi và in ra
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration <double> t = end - start;
            float time = t.count();
            cout<<" --- Result --- \n";
            p1.Score();
            cout <<"\n";
            p1.getTime(time);
            Sleep(1000);
            p1.reset();
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

    ketthuc:
    system("cls");
    cout<<"Thank you for your times";
    return 0;
}