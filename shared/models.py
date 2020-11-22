from django.db import models


class Columnist(models.Model):
    name = models.CharField(max_length=40)
    author = models.CharField(max_length=63)
    description = models.CharField(max_length=255)

    def __str__(self):
        return self.author


class Squad(models.Model):
    name = models.CharField(max_length=63)

    def __str__(self):
        return self.name

