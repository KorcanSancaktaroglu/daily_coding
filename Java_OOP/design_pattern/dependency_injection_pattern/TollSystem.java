// Package definition
package com.sancaktaroglu.dependencyinjection;

// 1. Interface for Logging/Saving
public interface ILoggable {
    void log(String message);
}

// 2. Concrete Implementations
public class TextFileLogger implements ILoggable {
    @Override
    public void log(String message) {
        System.out.println("Saved to TXT file: " + message);
    }
}

public class CloudLogger implements ILoggable {
    @Override
    public void log(String message) {
        System.out.println("Saved to Cloud: " + message);
    }
}

// 3. Context: The Toll System
public class TollSystem {
    private final ILoggable logger;

    // Dependency is injected through the constructor
    public TollSystem(ILoggable logger) {
        this.logger = logger;
    }

    public void detectIntruder() {
        System.out.println("Alarm! Intruder detected.");
        logger.log("Security Violation: Intruder detected.");
    }
}
