#include <iostream>
#define ll long long
using namespace std;
class counter{
  private:
      int  count;
   public:
    counter(int c){count=c;};
    counter operator++()//prefix
    {

        count++;
        return counter(count);

    }
    counter  operator++(int){
    count++;
        return counter(count);
    }
    int getc(){return count;}


};
class shape {
protected:
    int length, width;
    static int counter;

public:
    shape() : length(0), width(0) {
        counter++;
    }

    shape(int w, int l) : width(w), length(l) {
        counter++;
    }

    void setsha(int w, int l) {
        width = w;
        length = l;
    }

    virtual int area(){
        return width * length;
    }

    shape add_dist( shape obj) {
        return shape(width + obj.width, length + obj.length);
    }

    shape operator+ ( shape obj)  {
        return shape(width + obj.width, length + obj.length);
    }

    void displayshape()  {
        cout << "width: " << width << endl << "length: " << length << endl;
    }
    virtual void mm() final
{
    cout<<"mmm";
}
    static int getCounter() {
        return counter;
    }

//virtual void ufjf()=0;   bure fun -> bure class
};

int shape::counter = 0;

class rect : public shape {
private:
    int height;

public:
    rect(int w, int l, int h) : shape(w, l), height(h) {}

    void setrect(int w, int l, int h) {
        setsha(w, l);
        height = h;
    }

    int area()  override {
        return width * length*4; // لمنع الالتباس، هنا اختياري
    }

    int volume()  {
        return width * length * height;
    }

    void display()  {
        displayshape();
        cout << "height: " << height << endl;
        cout << "volume: " << volume() << endl;
        cout << "counter: " << getCounter() << endl;
    }
    friend void print (rect m);
//    ~rect(){
//    cout<<"class destroyed";
//    }

};

void print (rect m){ cout<<"friend "<<m.height;}

class person {
private:
    int age;
    string name;
public:
    person(int a, string n) : age(a), name(n) {}
    void display() {
        cout << "Name: " << name << "  Age: " << age << "\n";
    }
};

class employee : public person {
private:
    string title;
    double salary;
public:
    employee(string t, double s, int a, string n) : person(a, n), title(t), salary(s) {}
    void display() {
        person::display();
        cout << "Title: " << title << "  Salary: " << salary << "\n";
    }
};

class teacher : public employee {
private:
    string department;
    string course[4];
    int coursecount;
public:
    teacher(string d, string arr[], int count, string t, double s, int a, string n)
        : employee(t, s, a, n), department(d), coursecount(count) {
        if (count > 4) count = 4;
        for (int i = 0; i < count; i++) {
            course[i] = arr[i];
        }
    }
    void display() {
        employee::display();
        cout << "Department: " << department << "\nCourses: ";
        for (int i = 0; i < coursecount; i++) {
            cout << course[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
  

    // اختبار عمليات الجمع والنقيس
    shape obj1(5, 3), obj2(2, 3), obj3;
    obj3 = obj1 + obj2;

    obj3.displayshape();
    cout << endl;

    // اختبار الكائن الفرعي
    rect b1(23, 31, 43);
    b1.display();

    cout << endl;

    // استعلامات عن العنوان والمصفوفات
    int x = 24;
    int *ip = &x;
    int **mm = &ip; // عنوان مؤشر
    int arr[4]{2, 3, 1, 4};
    int *op = arr;
    char *a = "hello";

for(int i=0;i<4;i++){cout<<*(arr+i);}
cout<<endl;
    cout << "ip = " << ip << endl;
    cout << "*ip = " << *ip << endl;
    cout << "address pointer (mm) = " << mm << endl;
    cout << "ip array = " << op << endl;
    cout << "element array = " << *op << endl;
    cout << "*(op++) = " << *(op++) << endl;
    cout << "char *a = " << a << endl;
    cout << "char value *a = " << *a << endl;

    a++;
    cout << "*a = " << *a << endl;
    cout << "a (after increment) = " << a << endl;

    op++;
    cout << "*op = " << *op << endl;



    cout << endl<<endl;

    // استخدام المؤشر للنداء على الأسلوب المُفَصّل
    shape *ptr;
    ptr = &b1;
    cout << "Area of shape pointer (rect) = " << ptr->area() << endl;
ptr =&obj1;
 cout << "Area of shape pointer (shape) = " << ptr->area() << endl;
 print(b1);
 cout<<endl<<endl;


 int b, j;
 cout<<"enter num 1,num2"<<endl;
 cin>>b>>j;
 try{
 if(j==0)

  throw exception ();
  else
        cout<<"result divi "<<b/j<<endl;
 }

 catch (exception e){
 cout<<e.what()<<endl;

 }
 cout<<"prog cont"<<endl;


 try {
 if (b%2==0){
    throw string("even num");
 }

 }
 catch (string msg){
 cout<<msg<<endl;
 }
 int age ; cin>>age;  try{
 if(age<18)
    throw int (age);
 }
 catch (int x){
     cout<<x<<" under 18"<<endl;
 }

 catch(...)//->genral catch block
 {
     cout<<"error crach"<<endl;
 }
 counter hdj(5);
 ++hdj;
cout<< hdj.getc()<<endl;
 hdj++;
cout<< hdj.getc()<<endl;
 string courses[] = {"Math", "Physics", "Chemistry", "Biology"};
    teacher t("Science Dept", courses, 2, "Professor", 5000.0, 45, "Ahmed");
    t.display();
    return 0;

}
