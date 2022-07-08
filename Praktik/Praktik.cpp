#include <iostream>
#include <fstream>
#include <locale>
#include <string>



using namespace std;

//int main() {
//    setlocale(LC_ALL, "Rus");
//    fstream reading;
//    ofstream writing;
//    int cnt_l = 0, cnt_c = 0, cnt_num = 1;
//    int pos = 0;
//    int num;
//    string line;
//    reading.open("in.txt");
//    writing.open("out.txt");
//    bool flag = true, pass = false;
//    
//    
//    if (!reading.is_open())
//    {
//        cout << "Ошибка открытия файла journal.txt" << endl;
//    }
//    while (getline(reading, line, '\n'))
//    {
//        //cout << ++cnt_l << ' ';
//        if (!line.empty() ) {
//            for (int j = 0; j < line.length(); j++)
//            {
//                if (pass == false)
//                    cnt_c = 0;
//                pos = 0;
//               
//                for (int i = 0; i < line.length(); i++)
//                {
//                    if (line[i] == ' ' || i == line.length() - 1)
//                    {        
//                        if (i == line.length() - 1)
//                            num = stoi(line.substr(pos));
//                        else
//                            num = stoi(line.substr(pos, i - pos));
//                        if (pass == false) {
//                            cnt_c++;
//                            //cout << num << ' ';
//                        }
//                        pos = i;
//                        if (num == cnt_num)
//                            cnt_num++;
//                        //cout << cnt_num - 1 << ' ' << num << endl;
//                    }
//                }
//                pass = true;
// 
//            }
//            //cout << cnt_num - 1 << ' ' << cnt_c;
//            if (cnt_num - 1 != cnt_c)
//                flag = false;     
//            cnt_l++;
//            //cout << endl;
//        }
//        writing << line << endl;
//        if (line.empty() || reading.eof())
//        {       
//            if (cnt_c != cnt_l)
//                flag = false;
//            if (flag)
//                writing << "Матрица подходит по условию. Кол-во строк и столбцов: " << cnt_l << endl << endl << endl;
//                //cout << endl << "Матрица подходит по условию. Кол-во строк и столбцов: " << cnt_l << endl << endl;
//            else
//                writing << "Матрица не подходит по условию." << endl << endl << endl;
//                //cout << endl << "Матрица не подходит по условию." << endl << endl;
//            cnt_c = cnt_l = 0;
//            flag = true;
//        }
//        pass = false;
//        cnt_num = 1;
//    }
//   
//
//      
//    return 0;
//}

int num_maximum(int* arr, int size){
    int max;
    int num_max = 0;
    max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            num_max = i;
        }
    }
    if (max != -99999)
        return num_max;
    else
        return -1;
}

int num_minimum(int* arr, int size){
    int min;
    int num_min = 0;
    min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            num_min = i;
        }
    }
    if (min != 99999)
        return num_min;
    else
        return -1;
}

int main() {
    setlocale(LC_ALL, "Rus");
    fstream reading;
    int helper = 0;
    ofstream writing;
    int cnt_l = 0, cnt_c = 0, cnt_num = 1;
    int pos = 0;
    int num;
    string line;
    reading.open("read.txt");
    writing.open("out.txt");
    int** buffer;
    int* mult;
    int* sum;
    int min;
    int max;

    if (!reading.is_open())
    {
        cout << "Ошибка открытия файла read.txt" << endl;
    }
    while (getline(reading, line, '\n'))
    {
        //cout << line << endl;
        pos += line.length() + 2;
        if (!line.empty()) {
            cnt_l++;
        }
        if (line.empty() || reading.eof()) {

            mult = new int[cnt_l];
            sum = new int[cnt_l];

            buffer = new int* [cnt_l];
            for (int i = 0; i < cnt_l; i++) {
                buffer[i] = new int[cnt_l];
                mult[i] = 1;
                sum[i] = 0;
            }

            reading.seekg(helper);
            helper = pos;
            for (int i = 0; i < cnt_l; i++)
            {
                for (int j = 0; j < cnt_l; j++)
                {
                    reading >> buffer[i][j];
                    writing << buffer[i][j] << ' ';
                    if (buffer[i][j] % 2 == 1 && sum[i] != -99999)
                        sum[i] += abs(buffer[i][j]);
                    else 
                        sum[i] = -99999;
                    
                    if (abs(buffer[i][j]) <= 10 && mult[j] != 99999)
                        mult[j] *= abs(buffer[i][j]);
                    else 
                        mult[j] = 99999;
                    //cout << "\n\n\n\n" << sum[i] << ' ' << mult[j] << "\n\n\n\n" ;
                    //cout << endl;
                }




                writing << endl;
               
                /*if (!line.empty()) {
                    matrix.append(line);
                    matrix.append("\n");
                    cnt_l++;
                }
                if (line.empty() || reading.eof()) {

                    buffer = new int* [cnt_l];
                    for (int i = 0; i < cnt_l; i++) {
                        buffer[i] = new int[cnt_l];
                    }
                    stringstream ss(matrix);
                    for (int i = 0; i < cnt_l; i++)
                    {
                        for (int j = 0; j < cnt_l; j++)
                        {
                            ss >> buffer[i][j];
                            cout << buffer[i][j] << ' ';
                        }
                        cout << endl;
                    }

                    cnt_l = 0;
                    matrix.clear();
                    cout << endl << endl;*/
            }
            /*cout << "\n\n\n\n";
            for (int i = 0; i < cnt_l; i++)
            {
                cout << sum[i] << ' ';
            }
            cout << "\n";
            for (int i = 0; i < cnt_l; i++)
            {
                cout << mult[i] << ' ';
            }
            cout << "\n\n\n\n";*/
            max = num_maximum(sum, cnt_l);
            min = num_minimum(mult, cnt_l);
            if (max != -1) {
                writing << "Строка, подходящая по условию, с максимальной суммой элементов: ";
                for (int i = 0; i < cnt_l; i++)
                {
                    writing << buffer[max][i] << ' ';
                }
            }
            else
                writing << "Строки, подходящей по условию, в матрице нет.";
            writing << endl;
            if (min != -1) {
                writing << "Столбец, подходящий по условию, с минимальным произведением элементов: ";
                for (int i = 0; i < cnt_l; i++)
                {
                    writing << buffer[i][min] << ' ';
                }
            }
            else
                writing << "Столбца, подходящего по условию, в матрице нет.";
            writing << endl << endl << endl;
            for (int i = 0; i < cnt_l; i++)
                delete[]  buffer[i];
            delete[] buffer;
            delete[] mult;
            delete[] sum;
            cnt_l = 0;
            reading.seekg(helper);


        }


        


        
    }
    reading.close();
    writing.close();
    return 0;
}
