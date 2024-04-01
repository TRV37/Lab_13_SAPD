#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

//void Depth_First_Search(string Node, map<string, vector<string>>& Graph, map<string, bool>& Visited) 
//{
//    Visited[Node] = true;
//    cout << Node << endl;
//
//    for (auto& Adjacent : Graph[Node]) 
//        if (!Visited[Adjacent]) 
//            Depth_First_Search(Adjacent, Graph, Visited);
//        
//    
//}

void Depth_First_Search(string startNode, map<string, vector<string>>& Graph, map<string, bool>& Visited) 
{
    queue<string> List; // �������
    List.push(startNode);
    Visited[startNode] = true;

    while (!List.empty()) 
    {
        string Node = List.front();
        List.pop();
        cout << Node << endl;

        for (auto& Adjacent : Graph[Node]) 
            if (!Visited[Adjacent]) 
            {
                List.push(Adjacent);
                Visited[Adjacent] = true;
            }
        
    }
}

int main() 
{
    // ������� ������ ���������
    map<string, vector<string>> Graph;

    // ��������� �����
    Graph["Monument"].push_back("Downtown");
    Graph["Downtown"].push_back("Monument");

    Graph["Downtown"].push_back("CountrySide");
    Graph["CountrySide"].push_back("Downtown");

    Graph["Monument"].push_back("Central");
    Graph["Central"].push_back("Monument");

    Graph["CountrySide"].push_back("Central");
    Graph["Central"].push_back("CountrySide");

    // ������� ������ ��� ������������ ���������� �������
    map<string, bool> Visited;

    // �������� ������� ������ � �������
    Depth_First_Search("Monument", Graph, Visited);

    return 0;
}
