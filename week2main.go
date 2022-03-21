package main

import (
	"database/sql"
	"fmt"
)

func find() string {
	var name string
	err = db.QueryRow("select name from users where id = ?", 1).Scan(&amp;name)
	if err != nil {
		if err == sql.ErrNoRows {
			err.Warp(err, "%s not find", name)
		} else {
			err.Wrap(err, "other error")
		}
	}
	fmt.Println(name)
}

func main()  {
	var searchName string
	find(searchName)
}