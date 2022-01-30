We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running. Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.

Jobs: [[1,4,3], [2,5,4], [7,9,6]]
Output: 7
Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load (3+4=7) will be when both the
jobs are running at the same time i.e., during the time interval (2,4).

Jobs: [[6,7,10], [2,4,11], [8,12,15]]
Output: 15
Explanation: None of the jobs overlap, therefore we will take the maximum load of any job which is 15.

Jobs: [[1,4,2], [2,4,1], [3,6,5]]
Output: 8
Explanation: Maximum CPU load will be 8 as all jobs overlap during the time interval [3,4].

int findMaxCPULoad(vector<Job> &jobs) {
  if (jobs.empty()) {
    return 0;
  }

  // sort the jobs by start time
  sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) { return a.start < b.start; });

  int maxCPULoad = 0;
  int currentCPULoad = 0;
  priority_queue<Job, vector<Job>, endCompare> minHeap;
  for (auto job : jobs) {
    // remove all jobs that have ended
    while (!minHeap.empty() && job.start > minHeap.top().end) {
      currentCPULoad -= minHeap.top().cpuLoad;
      minHeap.pop();
    }

    // add the current job into the minHeap
    minHeap.push(job);
    currentCPULoad += job.cpuLoad;
    maxCPULoad = max(maxCPULoad, currentCPULoad);
  }

  return maxCPULoad;
}

Time complexity #
The time complexity of the above algorithm is O(N*logN), where ‘N’ is the total number of jobs. This is due to the sorting that we did in the beginning. Also, while iterating the jobs, we might need to poll/offer jobs to the priority queue. Each of these operations can take O(logN). Overall our algorithm will take O(NlogN).

Space complexity #
The space complexity of the above algorithm will be O(N), which is required for sorting. Also, in the worst case, we have to insert all the jobs into the priority queue (when all jobs overlap) which will also take O(N) space. The overall space complexity of our algorithm is O(N).
