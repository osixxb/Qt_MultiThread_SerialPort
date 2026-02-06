# Qt_MultiThread_SerialPort

## 📌 项目简介

这是一个基于 **Qt（C++）** 的多线程串口通信示例工程，  
用于演示和实现 **串口数据接收 / 解析 / 处理 / UI 显示** 的完整流程。

项目采用 **多线程模型**，将串口通信与界面逻辑解耦，  
适用于工业设备、仪表、控制系统等场景。

---

## ✨ 功能特性

- ✅ 串口参数可配置（端口号 / 波特率 / 校验位等）
- ✅ 独立串口通信线程，避免阻塞 UI
- ✅ 支持连续数据流接收
- ✅ 支持历史数据记录与曲线扩展
- ✅ 工程结构清晰，便于二次开发

---

## 🧱 工程结构说明

```text
Qt_MultiThread_SerialPort/
├── src/                # 核心源码（cpp / h）
├── ui/                 # Qt Designer UI 文件
├── curve/              # 运行时曲线 / 数据输出（不进 Git）
├── history/            # 历史数据 / 日志（不进 Git）
├── Qt_MultiThread_SerialPort.pro
├── README.md
├── .gitignore
```
