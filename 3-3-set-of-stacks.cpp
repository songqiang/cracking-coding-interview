/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Imagine a (literal) stack of plates. If the stack gets too high, it
might topple. There- fore, in real life, we would likely start a new
stack when the previous stack exceeds some threshold. Implement a data
structure SetOfStacks that mimics this. SetOf- Stacks should be
composed of several stacks, and should create a new stack once the
previous one exceeds capacity. SetOfStacks.push() and
SetOfStacks.pop() should behave identically to a single stack (that
is, pop() should return the same values as it would if there were just
a single stack). 

FOLLOW UP 

Implement a function popAt(int index) which performs a pop operation
on a specific sub-stack. 

 */

class SetOfStacks {
public:

    SetOfStacks(const size_t c) : capacity(c) {}

    Node
    pop()
    {
        while (!stacks.empty() && loads.back() == 0)
        {
            stacks.erase(stacks.end() - 1);
            loads.erase(loads.end() - 1);
        }
        
        if (stacks.empty())
            throw "EMPTY STACK";
        else
        {
            --loads.back();
            return stacks.back()->pop();
        }
    }
 	
    void
    push(Object item)
    {
        if (stacks.empty() || loads.back() == capacity)
        {
            stacks.push_back(unique_ptr<Stack>(new Stack));
            loads.push_back(0);
        }

        stacks.back().push(item);
        ++loads.back();
    }

    Node
    popAt(int index)
    {
        if (index >= 0 && index < stacks.size() && loads[index] > 0)
        {
            --loads[index];
            return stacks[index]->pop();
        }
        else
            throw "INVALID INDEX";
    }

private:
    size_t capacity;

    vector<unique_ptr<Stack> > stacks;
    vector<size_t> loads;
};

