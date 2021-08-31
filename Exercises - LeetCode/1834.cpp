class Solution {
public:
	vector<int> getOrder(vector<vector<int>>& tasks) {
		int n = tasks.size();
		if (n == 0) return {};
        
		//add the index in the end of each array for keeping track
		for (int i = 0; i < n; i++) {
			tasks[i].push_back(i);
		}
		
		sort(tasks.begin(), tasks.end());

		vector<int> ans;
		//push the task as {processing time, index} in the priority queue as min heap as per given in the problem
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; 
		long long time = tasks[0][0]; //set the current time to the first task in the array
		int i = 0;
		//push the initial tasks whose enque time is less than the current time
		while (i < n && tasks[i][0] <= time) {
			pq.push({ tasks[i][1], tasks[i][2] });
			i++;
		}

		while (!pq.empty()) {
			pair<int, int> task = pq.top();
			pq.pop();

			ans.push_back(task.second);
			time += task.first; //increment the time

			//if we don't have any task in our priority queue then set the time to the next task in the tasks array (in any)
			if (pq.empty()) {
				if (i < n) {
					time = max(time, tasks[i][0]);
				}
			}

			//push all the tasks whose enque time is less than or equal to the current time
			while (i < n && time >= tasks[i][0]) {
				pq.push({ tasks[i][1], tasks[i][2] });
				i++;
			}
		}

		return ans;
	}

private:
	long long max(long long a, int b) {
		if (a > b) {
			return a;
		}
		return b;
	}
};