class Solution {
public:

    void buildSegmentTree(int i, int l, int r,
                          vector<int>& segmentTree,
                          vector<int>& arr) {

        if (l == r) {
            segmentTree[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);

        segmentTree[i] = max(
            segmentTree[2 * i + 1],
            segmentTree[2 * i + 2]
        );
    }

    int querySegmentTree(int start, int end,
                         int i, int l, int r,
                         vector<int>& segmentTree) {

        if (l > end || r < start) {
            return INT_MIN;
        }

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        return max(
            querySegmentTree(start, end,
                             2 * i + 1, l, mid, segmentTree),

            querySegmentTree(start, end,
                             2 * i + 2, mid + 1, r, segmentTree)
        );
    }

    int RMQ(vector<int>& segmentTree,
            int n,
            int l,
            int r) {

        if (l > r) {
            return 0;
        }

        return querySegmentTree(
            l, r,
            0, 0, n - 1,
            segmentTree
        );
    }

    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {

        int n = s.size();

        int activeCount = count(
            s.begin(),
            s.end(),
            '1'
        );

        vector<int> blockStart;
        vector<int> blockEnd;

        int i = 0;

        while (i < n) {

            if (s[i] == '0') {

                int start = i;

                while (i < n && s[i] == '0') {
                    i++;
                }

                blockStart.push_back(start);
                blockEnd.push_back(i - 1);

            } else {
                i++;
            }
        }

        int m = blockStart.size();

        if (m < 2) {

            return vector<int>(
                queries.size(),
                activeCount
            );
        }

        vector<int> blockSize(m);

        for (int i = 0; i < m; i++) {

            blockSize[i] =
                blockEnd[i] -
                blockStart[i] + 1;
        }

    
        int N = m - 1;

        vector<int> pairSum(N);

        for (int i = 0; i < N; i++) {

            pairSum[i] =
                blockSize[i] +
                blockSize[i + 1];
        }

        vector<int> segmentTree(4 * N);

        buildSegmentTree(
            0,
            0,
            N - 1,
            segmentTree,
            pairSum
        );

        vector<int> result;

        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];

            int low = lower_bound(
                blockEnd.begin(),
                blockEnd.end(),
                l
            ) - blockEnd.begin();

            int high = upper_bound(
                blockStart.begin(),
                blockStart.end(),
                r
            ) - blockStart.begin() - 1;

            int maxPairSum = 0;

            if (low < high) {

                int firstLen =
                    blockEnd[low] -
                    max(blockStart[low], l) +
                    1;

                int lastLen =
                    min(blockEnd[high], r) -
                    blockStart[high] +
                    1;

                if (high - low == 1) {

                    maxPairSum =
                        firstLen +
                        lastLen;

                } else {

                    int pair1 =
                        firstLen +
                        blockSize[low + 1];

                    int pair2 =
                        blockSize[high - 1] +
                        lastLen;

                    int middleMax =
                        RMQ(
                            segmentTree,
                            N,
                            low + 1,
                            high - 2
                        );

                    maxPairSum = max({
                        pair1,
                        pair2,
                        middleMax
                    });
                }
            }

            
            result.push_back(
                activeCount +
                maxPairSum
            );
        }

        return result;
    }
};