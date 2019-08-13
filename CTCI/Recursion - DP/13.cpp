using namespace std;
#include <vector>
#include <algorithm>

int createStack(vector<Box> boxes){
    sort(boxes);
    vector<int> stackMap;
    return createStack(boxes, NULL, 0, stackMap);
}

int createStack(vector<Box> boxes, Box bottom, int offset, vector<int> stackMap){
    if(offset >= boxes.size()) return 0;

    //con base
    Box newBottom = boxes[offset];
    int heightWithBottom = 0;
    if(bottom == NULL || newBottom.canBeAbove(bottom)){
        if(stackMap[offset] == 0){
            offset = createStack(boxes, newBottom, offset +1, stackMap);
        }
        heightWithBottom = stackMap[offset];
    }

    // sin base
    int heightWithoutBottom = createStack(boxes, bottom, offset+1, stackMap);
    return abs(heightWithBottom, heightWithoutBottom);
}