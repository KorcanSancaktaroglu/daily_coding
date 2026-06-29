package com.sancaktaroglu;

import com.sancaktaroglu.designpatterns.observer.*;
import com.sancaktaroglu.designpatterns.strategy.*;
import com.sancaktaroglu.dependencyinjection.*;
import com.sancaktaroglu.singleton.AIConnector;

public class Main {
    public static void main(String[] args) {
        
        System.out.println("--- 1. Observer Pattern Demo ---");
        IntruderAlarmSystem alarm = new IntruderAlarmSystem();
        alarm.subscribe(new Police());
        alarm.subscribe(new FireDepartment());
        alarm.triggerAlarm();

        System.out.println("\n--- 2. Strategy Pattern Demo ---");
        TollFeeCalculator calculator = new TollFeeCalculator();
        calculator.setStrategy(new TruckTariff());
        System.out.println("Truck Fee: " + calculator.calculateFee(100));

        System.out.println("\n--- 3. Singleton Pattern Demo ---");
        AIConnector ai1 = AIConnector.getInstance();
        AIConnector ai2 = AIConnector.getInstance();
        System.out.println("Same instance? " + (ai1 == ai2)); // Should print true

        System.out.println("\n--- 4. Dependency Injection Demo ---");
        TollSystem system = new TollSystem(new CloudLogger());
        system.detectIntruder();
    }
}
