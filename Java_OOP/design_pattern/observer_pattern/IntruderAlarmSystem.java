// Package definition
package com.sancaktaroglu.designpatterns.observer;

import java.util.ArrayList;
import java.util.List;

// 1. Interface: The contract that all observers must follow
public interface IAlarmObserver {
    void onTrigger();
}

// 2. Concrete Observer: Police
public class Police implements IAlarmObserver {
    @Override
    public void onTrigger() {
        System.out.println("Notification sent to Police units: Alarm triggered!");
    }
}

// 3. Concrete Observer: Fire Department
public class FireDepartment implements IAlarmObserver {
    @Override
    public void onTrigger() {
        System.out.println("Notification sent to Fire Department: Emergency situation!");
    }
}

// 4. Subject: Alarm System
public class IntruderAlarmSystem {
    private final List<IAlarmObserver> subscribers = new ArrayList<>();

    public void subscribe(IAlarmObserver subscriber) {
        subscribers.add(subscriber);
    }

    public void unsubscribe(IAlarmObserver subscriber) {
        subscribers.remove(subscriber);
    }

    public void triggerAlarm() {
        System.out.println("System is initiating the alarm...");
        for (IAlarmObserver subscriber : subscribers) {
            subscriber.onTrigger();
        }
    }
}
