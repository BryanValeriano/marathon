from typing import List
import queue


def toposort(graph: List[List[int]], degree: List[int]) -> int:
    visited = 0
    ans = 1
    queueChapters = queue.Queue()
    timesNeedToRead = [1 for _ in range(len(degree))]

    for i in range(len(degree)):
        if degree[i] == 0:
            queueChapters.put(i)
    
    while (queueChapters.empty() == False):
        curentChapter = queueChapters.get()
        visited += 1
        ans = max(ans, timesNeedToRead[curentChapter])

        for neighbour in graph[curentChapter]:
            degree[neighbour] -= 1
            timesNeedToRead[neighbour] = max(timesNeedToRead[neighbour], timesNeedToRead[curentChapter] + (curentChapter > neighbour))
            if(degree[neighbour] == 0):
                queueChapters.put(neighbour)
    
    if(visited == len(degree)):
        return ans

    return -1


def main():
    tc = int(input())
    while(tc > 0):
        tc -= 1
        nChapters = int(input())
        degree = [1 for _ in range(nChapters)]
        graph = [[] for _ in range(nChapters)]
        for i in range(nChapters):
            requiredBeforeChapters = list(map(int, input().split()))
            degree[i] = requiredBeforeChapters[0]
            requiredBeforeChapters.pop(0)
            for requiredBefore in requiredBeforeChapters:
                graph[requiredBefore-1].append(i)
        print(toposort(graph, degree))

if __name__ == "__main__":
    main()

