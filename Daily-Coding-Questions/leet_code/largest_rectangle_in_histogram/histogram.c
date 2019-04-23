int largestRectangleArea(int heights, int heightsSize)
{
int stack = (int)malloc(heightsSize*sizeof(int));
int max_area = 0, area = 0;
int i = 0;
int position = -1, current_height = 0;

while ( i < heightsSize)
{
    if (position == -1 || heights[i] >= heights[stack[position]]) // check the maximum value of height it can reach
    {
        stack[++position] = i; // push in the stack all the index till we reach the maximum value of height
        i++;
    }
    else
    {
        current_height = stack[position--]; // pop out the peek which is current height
        area = (heights[current_height]) *( (position == -1) ? i : i - 1 - stack[position]); // calcuate area
        max_area = (max_area > area) ? max_area : area; // compare the area with the previous area's
    }
}

while(position >= 0) // Empty all the indexs of the stack and see if there is any combination for maximum area 
{
    current_height = stack[position--];
    area = (heights[current_height]) *( (position== -1) ? i : i - 1 - stack[position]);
    max_area = (max_area > area) ? max_area : area;
}
free(stack);
return max_area;
}

