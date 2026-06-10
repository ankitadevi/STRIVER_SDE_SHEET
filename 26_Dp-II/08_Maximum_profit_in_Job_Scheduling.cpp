// recursion
class Solution {
public:

    int solve(int idx,
              vector<vector<int>>& jobs) {

        if(idx == jobs.size())
            return 0;

        int nextIdx = lower_bound(
            jobs.begin() + idx + 1,
            jobs.end(),
            jobs[idx][1],
            [](const vector<int>& job, int endTime){
                return job[0] < endTime;
            }
        ) - jobs.begin();

        int take =
            jobs[idx][2] +
            solve(nextIdx, jobs);

        int notTake =
            solve(idx + 1, jobs);

        return max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs;

        for(int i=0;i<n;i++)
            jobs.push_back(
                {startTime[i],
                 endTime[i],
                 profit[i]});

        sort(jobs.begin(), jobs.end());

        return solve(0, jobs);
    }
};
// memo
class Solution {
public:

    int solve(int idx,
              vector<vector<int>>& jobs,
              vector<int>& dp){

        if(idx == jobs.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int nextIdx = lower_bound(
            jobs.begin()+idx+1,
            jobs.end(),
            jobs[idx][1],
            [](const vector<int>& job, int endTime){
                return job[0] < endTime;
            }
        ) - jobs.begin();

        int take =
            jobs[idx][2] +
            solve(nextIdx, jobs, dp);

        int notTake =
            solve(idx+1, jobs, dp);

        return dp[idx] =
               max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs;

        for(int i=0;i<n;i++)
            jobs.push_back(
                {startTime[i],
                 endTime[i],
                 profit[i]});

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n,-1);

        return solve(0,jobs,dp);
    }
};
// tab
class Solution {
public:

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs;

        for(int i=0;i<n;i++)
            jobs.push_back(
                {startTime[i],
                 endTime[i],
                 profit[i]});

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n+1,0);

        for(int idx=n-1; idx>=0; idx--){

            int nextIdx = lower_bound(
                jobs.begin()+idx+1,
                jobs.end(),
                jobs[idx][1],
                [](const vector<int>& job,
                   int endTime){
                    return job[0] < endTime;
                }
            ) - jobs.begin();

            int take =
                jobs[idx][2] +
                dp[nextIdx];

            int notTake =
                dp[idx+1];

            dp[idx] =
                max(take, notTake);
        }

        return dp[0];
    }
};

// | Approach    | TC           | SC     |
// | ----------- | ------------ | ------ |
// | Recursion   | (O(2^n))     | (O(n)) |
// | Memoization | (O(n\log n)) | (O(n)) |
// | Tabulation  | (O(n\log n)) | (O(n)) |
