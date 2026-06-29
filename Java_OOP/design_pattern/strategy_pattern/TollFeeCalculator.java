// Package definition
package com.sancaktaroglu.designpatterns.strategy;

// 1. Strategy Interface
public interface ITollFeeStrategy {
    double calculate(double baseFee);
}

// 2. Concrete Strategies
public class CarTariff implements ITollFeeStrategy {
    @Override
    public double calculate(double baseFee) {
        return baseFee * 1.2;
    }
}

public class TruckTariff implements ITollFeeStrategy {
    @Override
    public double calculate(double baseFee) {
        return (baseFee * 2.5) + 500;
    }
}

// 3. Context: The Toll Fee Calculator
public class TollFeeCalculator {
    private ITollFeeStrategy strategy;

    public void setStrategy(ITollFeeStrategy strategy) {
        this.strategy = strategy;
    }

    public double calculateFee(double baseFee) {
        if (strategy == null) {
            throw new IllegalStateException("Strategy not set!");
        }
        return strategy.calculate(baseFee);
    }
}
