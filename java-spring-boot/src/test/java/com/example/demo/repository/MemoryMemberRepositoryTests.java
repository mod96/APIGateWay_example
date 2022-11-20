package com.example.demo.repository;

import com.example.demo.domain.Member;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.List;
import java.util.Optional;

public class MemoryMemberRepositoryTests {
    MemoryMemberRepository repository = new MemoryMemberRepository();

    @BeforeEach
    public void clear() {
        repository.clearStore();
    }

    @Test
    public void save() {
        Member member = new Member();
        member.setName("spring");
        repository.save(member);

        Optional<Member> result = repository.findById(member.getId());
        Assertions.assertTrue(result.isPresent());
        Assertions.assertEquals(result.get(), member);
    }

    @Test
    public void findByName() {
        Member member1 = new Member();
        member1.setName("spring1");
        repository.save(member1);

        Member member2 = new Member();
        member1.setName("spring1");
        repository.save(member2);

        Optional<Member> result = repository.findByName("spring1");
        Assertions.assertTrue(result.isPresent());
        Assertions.assertEquals(result.get(), member1);
    }

    @Test
    public void findAll() {
        Member member1 = new Member();
        member1.setName("spring1");
        repository.save(member1);

        Member member2 = new Member();
        member1.setName("spring1");
        repository.save(member2);

        List<Member> result = repository.findAll();

        Assertions.assertEquals(result.size(), 2);
    }
}
