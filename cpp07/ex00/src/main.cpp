#include "../include/temp.hpp"



int main()
{
    //teste template max int
    std::cout << "INT\t-" << "max(1, 2) = " << max(1, 2) << std::endl << std::endl;
    //teste template max float
    std::cout << "FLOAT\t-" << "max(1.1, 2.2) = " << max(1.1, 2.2) << std::endl << std::endl;
    //teste template max string
    std::cout << "STRING\t-" << "max(\"abc\", \"cba\") = " << max("abc", "cba") << std::endl << std::endl;
    //teste template max char
    std::cout << "CHAR\t-" << "max('a', 'b') = " << max('a', 'b') << std::endl << std::endl;

    std::cout << "--------------------------------" << std::endl;
    //teste template min int
    std::cout << "INT\t -" << "min(1, 2) = " << min(1, 2) << std::endl << std::endl;
    //teste template min float
    std::cout  << "FLOAT\t -" << "min(1.1, 2.2) = " << min(1.1f, 2.2f) << std::endl << std::endl;
    //teste template min string
    std::cout  << "STRING\t -" << "min(\"abc\", \"cba\") = " << min("abc", "cba") << std::endl << std::endl;
    //teste template min char
    std::cout  << "CHAR\t -" << "min('a', 'b') = " << min('a', 'b') << std::endl << std::endl;
    std::cout << "--------------------------------" << std::endl;

    //teste template swap int
    int a = 1;
    int b = 2;
    std::cout << "INT\t -" << "swap(a, b) = " << swap(a, b) << std::endl << std::endl;
    //teste template swap float
    float c = 1.1f;
    float d = 2.2f;
    std::cout << "FLOAT\t -" << "swap(c, d) = " << swap(c, d) << std::endl << std::endl;
    //teste template swap string
    std::string e = "abc";
    std::string f = "cba";
    std::cout << "\te == " << e;
    std::cout << "; f == " << f << std::endl;
    swap(e, f);
    std::cout << "STRING\t -" << "swap(e, f)" << std::endl;
    std::cout << "\te == " << e;
    std::cout << "; f == " << f << std::endl;
    //teste template swap char
    char g = 'a';
    char h = 'b';
    std::cout << std::endl;
    std::cout << "CHAR\t -" << "swap(g, h) = " << swap(g, h) << std::endl;



    return 0;
}
