// See demo: https://www.dropbox.com/s/w083vl2m7salyqf/interview_resizing.gif

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Rectangle {
  constexpr static double MIN_HEIGHT = 1.0;
  double height;

  Rectangle(double height_): height(height_) {}

  string toString() const {
    std::ostringstream str;
    str << "Rectangle(h=" << height << ")\n";
    return str.str();
  }
};

/*
This function mutates the input rectangles with their new heights
after distributing the heightDelta across all rectangles.

For example, the following numbers represent the height of three selected rectangles:
[10][3][10]

Resizing them by +12 results in the following heights:
[10+4][3+4][10+4]

Resizing them by -12 results in the following heights:
[10-5][3-2][10-5]



Note that the middle rectangle's height cannot be reduced beyond Rectangle.minHeight, which is 1
*/

void resizeRectangles(vector<Rectangle> &rectangles, double heightDelta, int remainingElements) {

  for (int i = 0; i < rectangles.size(); i++) {
    cout << rectangles[i].height << endl;
  }

  cout << " ---------------- " << endl;

  if (heightDelta == 0 ) {
    return ;
  }

  //int initialElements = remainingElements;
  int remainingHeight =  heightDelta;

  int size = rectangles.size();
  double heightToGive = heightDelta / remainingElements;

  for (int i = 0; i < size; i++) {
    if (rectangles[i].height + heightToGive >= rectangles[i].MIN_HEIGHT) {
      rectangles[i].height = rectangles[i].height + heightToGive;
      remainingHeight = remainingHeight - heightToGive;

    } else if (rectangles[i].height != rectangles[i].MIN_HEIGHT) {
      remainingHeight = remainingHeight + (rectangles[i].height - rectangles[i].MIN_HEIGHT);
      rectangles[i].height = rectangles[i].MIN_HEIGHT;


    }
    if (rectangles[i].height == rectangles[i].MIN_HEIGHT) {
      remainingElements--;
    }
  }
  cout << "remainingElements" << remainingElements << endl;
  if (remainingElements > 0) {
    //cout << "remainingElements" << remainingElements << endl;
    resizeRectangles(rectangles, remainingHeight, remainingElements);
  }
}



int main() {
  vector<Rectangle> rectangles = {
    Rectangle(10),
    Rectangle(3),
    Rectangle(10)
  };

  //resizeRectangles(rectangles, 12, rectangles.size()); // should return [14, 7, 14]
  //resizeRectangles(rectangles, -12, rectangles.size()); // should return [5, 1, 5]

   rectangles = rectangles = {
     Rectangle(10),
     Rectangle(3),
     Rectangle(5)
   };
   resizeRectangles(rectangles, -12, rectangles.size()); // should return [4,1,1]
  // resizeRectangles(rectangles, -15, rectangles.size()); // should return [1,1,1]

  // 10-4 -4, 3-2, 5-4

  return 0;
}
