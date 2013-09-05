/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

How would you design a stack which, in addition to push and pop, also
has a function min which returns the minimum element? Push, pop and
min should all operate in O(1) time.

 */

class Stack
{
public:
    void push(const size_t v) 
    {
        if (vals.empty())
        {
            vals.push_back(v);
            min_vals.push_back(v);
        }
        else
        {
            vals.push_back(v);
            min_vals.push_back(min(v, min_vals.back()));
        }
    }

    size_t pop() 
    {
        if (!vals.empty())
        {
            const size_t v = vals.back();
            vals.erase(vals.end() - 1);
            min_vals.erase(min_vals.end() - 1);
            return v;
        }
        else
            throw ("EMPTY STACK");
    }

    size_t min() const 
    {
        if (!min_vals.empty())
            return min_vals.back();
        else
            throw("EMPTY STACK");
    }

private:
    vector<size_t> vals
    vector<size_t> min_vals;
};
