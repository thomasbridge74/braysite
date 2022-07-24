from django.db import models
from shared.models import Squad


class Player(models.Model):
    firstname = models.CharField(max_length=255)
    surname = models.CharField(max_length=255)
    current = models.BooleanField(default=True)
    story = models.TextField()
    picture_url = models.CharField(
        max_length=255, null=True, default=None
    )  # noqa: DJ01

    def __str__(self):
        return f"{self.firstname} {self.surname}"


class SquadEntry(models.Model):  # noqa: DJ08
    player = models.ForeignKey(Player, on_delete=models.PROTECT)
    squad = models.ForeignKey(Squad, on_delete=models.PROTECT)
