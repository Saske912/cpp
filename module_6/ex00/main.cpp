//
//                                       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣴⣖⣁⣀⣀⡄⠀⠀⠀
//                                       ⠀⠀⠀⠀⠀⠀⢀⣀⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣤⣄⣀⣀
//                                      ⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁
//                                      ⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀
//                                      ⠀⠀⠀⠀⠀⣼⣿⡟⠀⢠⡲⠖⠀⣿⣿⣿⣿⣿⣿⣿⣉⠁⠀⠀⠀
//  ╱╱╱╱╭━╮╭╮                               ⣼⣿⣿⡷⢤⠤⠤⣥⡤⣿⠿⣿⣿⣿⡿⣿⣿⣷⡀
//  ╱╱╱╱┃╭╯┃┃                           ⠀⣀⣠⣼⣿⣿⣿⣧⠑⠟⠀⠈⠙⠱⢦⣿⣿⣿⠁⣸⣿⣿⣇⠀
//  ╭━━┳╯╰┳┫┃╭━━╮                       ⠊⠉⠉⠉⠉⠩⠞⠁⠀⠀⠄⠀⠀⡴⣿⣿⣿⠗⣵⣿⠡⠉⠉⠁⠀
//  ┃╭╮┣╮╭╋┫┃┃┃━┫                              ⠀⢡⠀⠀⠀⢈⣾⣟⣵⣯⣼⣿⣬⣄⣀⠀⠀
//  ┃╰╯┃┃┃┃┃╰┫┃━┫                           ⠀⠀⣶⣶⣶⣾⣥⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀
//  ┃╭━╯╰╯╰┻━┻━━╯                           ⠀⢺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⡄
//  ┃┃                                     ⢠⢤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⡄
//  ╰╯                                  ⠀⠠⣰⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠇⠀
// 06.03.2021⠀⠀⠀⠀
//
#include <string>
#include <iostream>
#include <cmath>

void    nan()
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: "<< std::numeric_limits<double>::quiet_NaN() << std::endl;
}

void    plus_inf()
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
}

void    minus_inf()
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: -" << std::numeric_limits<float>::infinity() << "f" << std::endl;
    std::cout << "double: -inf" << std::endl;
}

void    print_vals(char c, int i, float f, double d)
{
    std::cout << "char: ";
    if (i > 31 and i < 127)
        std::cout << "'" << c << "'" << std::endl;
    else if (i > 255 or i < 0)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " <<  d << std::endl;
}

int     len_i(int i)
{
    int len;
    len = 1;
    while(i /= 10)
        len++;
    return len;
}

void    print_vals_zero(char c, int i, float f, double d)
{
    std::cout << "char: ";
    if (i > 31 and i < 127)
        std::cout << "'" << c << "'" << std::endl;
    else if (i > 255 or i < 0)
        std::cout << "Impossible" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    if (len_i(i) < 7)
    {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " <<  d << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " <<  d  << std::endl;
    }

}

void    char_c(char c)
{
    print_vals_zero(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
}

void    int_c(int i)
{
    print_vals_zero((char)i, i, (double)i, (float)i);
}

void    print_vals_impos(double c, float k)
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: " << k << "f" << std::endl;
    std::cout << "double: " << c << std::endl;
}

void    double_c(double c, int dot)
{
    if (c < static_cast<double>(std::numeric_limits<int>::min()) \
            or c > static_cast<double>(std::numeric_limits<int>::max()))
            print_vals_impos(c, (float)c);
    else
    {
        if (dot)
            print_vals((char)c, (int)c, c, (float)c);
        else
            print_vals_zero((char)c, (int)c, c, (float)c);
    }
}

void    float_c(float c, int dot)
{
//    std::cout << std::numeric_limits<float>::min() << std::endl;
//    std::cout << std::numeric_limits<float>::max() << std::endl;
    if (c < static_cast<float >(std::numeric_limits<int>::min()) \
            or c > static_cast<float >(std::numeric_limits<int>::max()))
        print_vals_impos((double)c, c);
    else
    {
        if (dot)
            print_vals((char)c, (int)c, (double)c, c);
        else
            print_vals_zero((char)c, (int)c, c, (float)c);
    }
}

int     str_is_numeric(std::string str)
{
    int     i;

    i = 0;
    if (str[i] == '-' or str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] < 48 or str[i] > 57)
            return (0);
        i++;
    }
    return (1);
}

int     str_is_double(std::string str, int &dot)
{
    int     i;
    int     k;
    int     n;

    i = 0;
    k = 1;
    if (str[i] == '-' or str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] < 48 or str[i] > 57)
        {
            if (str[i] == '.' and k)
            {
                k--;
                n = i;
                while (str[n])
                {
                    n++;
                    if ((str[n] && str[n] != 48) or i > 6)
                    {
                        dot = 1;
                    }
                }
            }
            else
            {
                dot = 0;
                return (0);
            }
        }
        i++;
    }
    return (1);
}

int     str_is_float(std::string tmp, int &dot)
{
    if (tmp[tmp.length() - 1] == 'f')
    {
        if (str_is_double(tmp.erase(tmp.length() - 1, 1), dot))
        {
            return(1);
        }
    }
    return (0);
}

void    got_type(std::string tmp)
{
    int dot_zero;

    dot_zero = 0;
    if (tmp.length() == 1 && (tmp[0] > 31 && tmp[0] < 127) \
    && !(tmp[0] > 47 && tmp[0] < 58))
        char_c(static_cast<char>(tmp[0]));
    else if (str_is_numeric(tmp))
    {
        long int t = atol(tmp.c_str());
        if (t < static_cast<long int>(std::numeric_limits<int>::min()) \
        or t > static_cast<long int>(std::numeric_limits<int>::max()))
            std::cout << "please don't overflow integer" << std::endl;
        else
            int_c(atoi(tmp.c_str()));
    }
    else if (str_is_double(tmp, dot_zero))
    {
        double_c(atof(tmp.c_str()), dot_zero);
    }
    else if (str_is_float(tmp, dot_zero))
    {
        double t = atof(tmp.c_str());
        if (fabs(t) > static_cast<double >(std::numeric_limits<float>::max()))
            std::cout << "please don't overflow float" << std::endl;
        else
            float_c((float)atof(tmp.c_str()), dot_zero);
    }
    else
        std::cout << "string is not recognized, please try again" << std::endl;
}

int     main(int ac, char **av)
{
    std::string tmp;

    if (ac == 2)
    {
        tmp = av[1];
        if (tmp == "nan" or tmp == "nanf")
            nan();
        else if (tmp == "+inf" or tmp == "+inff")
            plus_inf();
        else if (tmp == "-inf" or tmp == "-inff")
            minus_inf();
        else
        {
            got_type(tmp);
        }
    }
    else
        std::cout << "Please enter 1 argument(char int float or double)" << std::endl;
    return 0;
}