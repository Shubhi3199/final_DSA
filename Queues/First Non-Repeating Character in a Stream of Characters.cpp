// https://www.interviewbit.com/old/problems/first-non-repeating-character-in-a-stream-of-characters/
string Solution::solve(string A) {
    queue<char> q;
    unordered_map<char, int> map;
    string res;
    for (char ch: A) {
        map[ch]++;
        if (map[ch] == 1) q.push(ch);
        while (!q.empty() and map[q.front()] > 1) q.pop();
        if (q.empty()) res += "#";
        else res.push_back(q.front());
    }
    return res;
}
