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
    queue<string> List; // очередь
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
    // Создаем список смежности
    map<string, vector<string>> Graph;

    // Добавляем ребра
    Graph["Monument"].push_back("Downtown");
    Graph["Downtown"].push_back("Monument");

    Graph["Downtown"].push_back("CountrySide");
    Graph["CountrySide"].push_back("Downtown");

    Graph["Monument"].push_back("Central");
    Graph["Central"].push_back("Monument");

    Graph["CountrySide"].push_back("Central");
    Graph["Central"].push_back("CountrySide");

    // Создаем массив для отслеживания посещенных станций
    map<string, bool> Visited;

    // Вызываем функцию поиска в глубину
    Depth_First_Search("Monument", Graph, Visited);

    return 0;
}
