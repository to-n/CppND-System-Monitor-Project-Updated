#ifndef SYSTEM_PARSER_H
#define SYSTEM_PARSER_H

#include <fstream>
#include <regex>
#include <string>

namespace LinuxParser {
// Paths
const std::string kProcDirectory{"/proc/"};
const std::string kCmdlineFilename{"/cmdline"};
const std::string kCpuinfoFilename{"/cpuinfo"};
const std::string kStatusFilename{"/status"};
const std::string 
kStatFilename{"/stat"};
const std::string kUptimeFilename{"/uptime"};
const std::string kMeminfoFilename{"/meminfo"};
const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};
const std::string kPasswordPath{"/etc/passwd"};

// Text labels
const std::string kLabelTotalProcesses{"processes"};
const std::string kLabelRunningProcesses{"procs_running"};
const std::string kEmpty{""};
const std::string kLabelUid("Uid:");
const std::string kLabelRam("VmSize:");
const std::string kLabelCpu("cpu");
const std::string kLabelMemTotal("MemTotal:");
const std::string kLabelMemFree("MemFree:");
const std::string kLabelBuffers("Buffers:");
const std::string kLabelCached("Cached:");
const std::string kLabelSReclaimable("SReclaimable:");
const std::string kLabelShmem("Shmem:");
const std::string kLabelSwapTotal("SwapTotal:");
const std::string kLabelSwapFree("SwapFree:");

// Numerical error return values
const int kErrInt = -1;
const int kErrFloat = -1.0;







// System
float MemoryUtilization();
long UpTime();
std::vector<int> Pids();
int TotalProcesses();
int RunningProcesses();
std::string OperatingSystem();
std::string Kernel();

// CPU
enum CPUStates {
  kUser_ = 0,
  kNice_,
  kSystem_,
  kIdle_,
  kIOwait_,
  kIRQ_,
  kSoftIRQ_,
  kSteal_,
  kGuest_,
  kGuestNice_
};

std::vector<std::string> CpuUtilization();
long Jiffies();
long Jiffies(int pid);
long ActiveJiffies();
long ActiveJiffies(int pid);
long IdleJiffies();

// Processes
std::string Command(int pid);
std::string Ram(int pid);
std::string Uid(int pid);
std::string User(int uid);
long int UpTime(int pid);
float CpuUtilization(int pid);
};  // namespace LinuxParser

#endif