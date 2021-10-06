#include "CJsonObject.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

const string IN_PUT_FILE = "./in.json";
const string OUT_PUT_FILE = "./out.json";

void Input(neb::CJsonObject &cJson)
{
    // exist judge
    cout << "cJson.KeyExist(\"book\"): " << cJson.KeyExist("book") << endl;

    neb::CJsonObject &book = cJson["book"];

    cout << "book.GetArraySize(): " << book.GetArraySize() << endl;
    for (int i = 0; i < book.GetArraySize(); i++) {
        cout << "Output array index " << i << endl;
        cout << "id\tlanguage\tedition\tauthor\n";
        string id,language,edition,author;
        book[i].Get("id", id);
        book[i].Get("language", language);
        book[i].Get("edition", edition);
        book[i].Get("author", author);
        cout << id << "\t" << language << "\t" << edition << "\t" << author << endl;
    }
}

void Add(neb::CJsonObject &cJson)
{
    cJson.AddEmptySubObject("result");
    cJson["result"].Add("size", 3);
    cJson["result"].AddEmptySubArray("option");
    cJson["result"]["option"].Add("move");
    cJson["result"]["option"].Add("run");
    cJson["result"]["option"].Add("stay");
}

void Output(neb::CJsonObject &cJson)
{
    cout << cJson.ToFormattedString() << endl;

    ofstream fout(OUT_PUT_FILE);
    fout << cJson.ToFormattedString();
    fout.close();
}

int main()
{
    ifstream fin(IN_PUT_FILE);
    if (fin.bad()) {
        cout << "err in fstream " << endl;
        return -1;
    }

    neb::CJsonObject cJson;
    stringstream ss;
    ss << fin.rdbuf();
    fin.close();

    auto result = cJson.Parse(ss.str());
    if (!result) {
        cout << "cJson parse error " << endl;
        return -1;
    }

    // 输出格式化的JSON内容
    cout << cJson.ToFormattedString() << endl;

    Input(cJson);
    Add(cJson);
    Output(cJson);

    return 0;
}