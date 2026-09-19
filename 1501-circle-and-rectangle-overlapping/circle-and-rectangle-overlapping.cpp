class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find the closest point of the rectangle to the circle's center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate squared distance
        int dx = closestX - xCenter;
        int dy = closestY - yCenter;

        int distanceSquared = dx * dx + dy * dy;

        // Check whether this point lies inside/on the circle
        return distanceSquared <= radius * radius;
    }
};