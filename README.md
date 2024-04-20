# OS_Schedular_GUI
**CPU Scheduler GUI Application**

This project is a CPU scheduler desktop application implemented using Qt framework in C++. The application supports various types of scheduling algorithms and provides a graphical user interface for visualizing the scheduling process.

### Features
- Supports multiple scheduling algorithms:
  1. First-Come, First-Served (FCFS)
  2. Shortest Job First (SJF) - Preemptive and Non-Preemptive
  3. Priority Scheduling - Preemptive and Non-Preemptive
  4. Round Robin
- Dynamically add processes while the scheduler is running.
- Live visualization of the scheduling process through a Gantt chart.
- Calculation of average waiting time and average turnaround time.
- Live updating of the remaining burst time table as time progresses.
- Option to run existing processes without live scheduling.

### Requirements
- Qt framework
- C++ compiler (e.g., GCC)

### Usage
1. Clone the repository to your local machine:

```bash
git clone https://github.com/your-username/cpu-scheduler.git
```

2. Open the project in Qt Creator or any other IDE that supports Qt projects.

3. Build the project to generate the executable file.

4. Run the executable file (`cpu_scheduler.exe` on Windows) to launch the application.

5. Select the desired scheduling algorithm from the dropdown menu.

6. Enter the required information about each process according to the selected scheduler type.

7. Optionally, dynamically add new processes while the scheduler is running.

8. Visualize the scheduling process through the live-updated Gantt chart.

9. View the average waiting time, average turnaround time, and the remaining burst time updated table.


### Acknowledgments
- Special thanks to [Qt](https://www.qt.io/) for providing the powerful framework for developing GUI applications.

Feel free to modify and enhance the project as needed. If you encounter any issues or have suggestions for improvements, please create an issue or submit a pull request on GitHub. Thank you for using our CPU Scheduler GUI Application!
