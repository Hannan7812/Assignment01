#include <iostream>
#include <string>
using namespace std;

class ProcessNode{
    public:
    string process_id;
    int execution_time;
    int remaining_time;
    ProcessNode* next;

    ProcessNode(string id, int execution_time){
        this->process_id = id;
        this->execution_time = execution_time;
        this->remaining_time = execution_time;
        this->next = nullptr;
    }
};

class ProcessSchedulingCircularLinkedList{
    public:
    int cycle_time;
    ProcessNode* list;
    ProcessNode* ploc;

    ProcessSchedulingCircularLinkedList(int cycle_time){
        this->cycle_time = cycle_time;
        this->list = nullptr;
        this->ploc = nullptr;
    }

    void add_process(ProcessNode* process){
        cout << "Adding new process " << process->process_id << '\n';
        if (!this->list){
            this->list = process;
            this->list->next = process;
            return;
        }
        else{
            process->next = this->list->next;
            this->list->next = process;
            this->list = this->list->next;
        }
    }

    int apply_execution(ProcessNode* loc){
        if (loc->remaining_time - this->cycle_time <= 0){
            loc->remaining_time = 0;
            return 0;
        }
        else{
            loc->remaining_time -= this->cycle_time;
            return loc->remaining_time;
        }
    }

    void execute_cycle(){
        if (!list){
            cout << "No processes" << '\n';
            return;
        }
        ProcessNode* ploc = this->list;
        ProcessNode* loc = this->list->next;

        do{
            int status = apply_execution(loc);
            if (status == 0){
                cout << loc->process_id << "(Completed) ";
            }
            else{
                cout << loc->process_id << "(Remaining: " << loc->remaining_time << ") ";
            }
            loc = loc->next;
            ploc = ploc->next;
        } 
        while (loc != this->list->next);
        cout << '\n';

        loc = this->list->next;
        ploc = this->list;

        while (loc != this->list){
            if (loc->remaining_time == 0){
                ProcessNode* temp = loc;
                loc = loc->next;
                ploc->next = loc;
                delete temp;
                continue;
            }
            loc = loc->next;
            ploc = ploc->next;
        }

        if (loc->remaining_time == 0){
            if (this->list->next == this->list){
                this->list = nullptr;
                cout << "No more processes" << '\n';
            }
            else{
                ploc->next = loc->next;
                this->list = ploc;
                delete loc;
            }
        }
    }

    void simulate_execution(){
        this->add_process(new ProcessNode("P1", 9));
        this->add_process(new ProcessNode("P2", 7));
        this->add_process(new ProcessNode("P3", 3));
        this->execute_cycle();
        this->execute_cycle();
        this->add_process(new ProcessNode("P4", 11));
        this->execute_cycle();
        this->add_process(new ProcessNode("P6", 2));
        while (this->list){
            this->execute_cycle();
        }
    }
    
};

int main(){
    ProcessSchedulingCircularLinkedList* p = new ProcessSchedulingCircularLinkedList(3);
    p->simulate_execution();
    delete p;
}