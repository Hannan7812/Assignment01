#include <iostream>
#include <string>
using namespace std;

// Class representing a process node in the circular linked list
class ProcessNode{
    public:
    string process_id; // ID of the process
    int execution_time; // Total execution time required by the process
    int remaining_time; // Remaining execution time for the process
    ProcessNode* next; // Pointer to the next process node

    // Constructor to initialize a process node
    ProcessNode(string id, int execution_time){
        this->process_id = id;
        this->execution_time = execution_time;
        this->remaining_time = execution_time;
        this->next = nullptr;
    }
};

// Class representing the process scheduling using a circular linked list
class ProcessSchedulingCircularLinkedList{
    public:
    int cycle_time; // Time slice for each cycle
    ProcessNode* list; // Pointer to the last node in the circular linked list
    ProcessNode* ploc; // Pointer to the current location in the list

    // Constructor to initialize the scheduling list with a given cycle time
    ProcessSchedulingCircularLinkedList(int cycle_time){
        this->cycle_time = cycle_time;
        this->list = nullptr;
        this->ploc = nullptr;
    }

    // Method to add a new process to the circular linked list
    void add_process(ProcessNode* process){
        cout << "Adding new process " << process->process_id << '\n';
        if (!this->list){
            // If the list is empty, initialize it with the new process
            this->list = process;
            this->list->next = process;
            return;
        }
        else{
            // Insert the new process into the circular linked list
            process->next = this->list->next;
            this->list->next = process;
            this->list = this->list->next;
        }
    }

    // Method to apply execution time to a process node
    int apply_execution(ProcessNode* loc){
        if (loc->remaining_time - this->cycle_time <= 0){
            // If the remaining time is less than or equal to the cycle time, set it to 0
            loc->remaining_time = 0;
            return 0;
        }
        else{
            // Otherwise, reduce the remaining time by the cycle time
            loc->remaining_time -= this->cycle_time;
            return loc->remaining_time;
        }
    }

    // Method to execute one cycle of the scheduling
    void execute_cycle(){
        if (!list){
            cout << "No processes" << '\n';
            return;
        }
        ProcessNode* ploc = this->list;
        ProcessNode* loc = this->list->next;

        // Apply execution to each process in the list
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

        // Remove completed processes from the list
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

        // Special case for the last process in the list
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

    // Method to simulate the execution of processes
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
    // Create a new process scheduling list with a cycle time of 3
    ProcessSchedulingCircularLinkedList* p = new ProcessSchedulingCircularLinkedList(3);
    // Simulate the execution of processes
    p->simulate_execution();
    // Clean up the allocated memory
    delete p;
}