package com.example.demo.controller;

import lombok.*;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {
    @GetMapping("/hello")
    public String hello(@RequestParam(value = "name", defaultValue = "World") String name) {
        return String.format("Hello %s!", name);
    }

    @GetMapping("/hello-obj")
    public Hello helloObj(@RequestParam(value = "name", defaultValue = "World") String name) {
        return new Hello(name);
    }

    @Data
    @Builder
    @AllArgsConstructor
    @NoArgsConstructor
    static class Hello {
        private String name;
    }
}
